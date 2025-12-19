
实例八：方便并发运行命令的工具

功能：

我们经常会遇到在循环里批量处理文件的场景（比如将所有 jpg 图片转换成 png 图片），那么就会遇到一个麻烦：如果在前台处理文件，那同一时间只能处理一个，效率太低；如果在后台处理文件，那么瞬间就会启动很多个进程，占用大量资源，系统难以承受。我们希望的是在同一时间最多同时处理固定数量（比如 10 个）的文件，如果已经达到了这个数量，那么就先等一会，直到有退出的进程后再继续。parallel 命令中在一定程度上能满足这个需求，但用起来太麻烦。

例子：

# rr 是一个函数（可放在 .zshrc 中），直接 rr 加命令即可使用
# 命令中支持变量、重定向等等，格式上和直接输入命令没有区别（不支持 alias）
% rr sleep 5
[4] 5031
% rr sleep 5
[5] 5032

# 如果不加参数，则显示当前运行的进程数、最大进程并发数和运行中进程的进程号
# 默认最大进程并发数是 10
% rr
running/max: 2/10
pid: 5031 5032
# 5 秒之后，运行结束
% rr
running/max: 0/10


# 用 -j 来指定最大进程并发数，指定一次即可，如需修改可再次指定
# 可以只调整最大进程并发数而不运行命令
% rr -j2 sleep 10
[4] 5035
% rr sleep 10
[5] 5036

# 超过了最大进程并发数，等待，并且每一秒检查一次是否有进程退出
# 如果有进程退出，则继续在后台运行当前命令
% rr sleep 10
running/max: 2/2, wait 1s ...
pid: 5035 5036
running/max: 2/2, wait 1s ...
pid: 5035 5036
[4]  - done       $*
[4] 5039


# 实际使用场景，批量将 jpg 图片转换成 png 图片，gm 是 graphicsmagick 中的命令
# 转换图片格式比较耗时，顺序执行的话需要很久
% for i (*.jpg) { rr gm convert $i ${i/jpg/png} }
[4] 5055
[5] 5056
[6] 5057
[7] 5058
[8] 5059
[9] 5060
[10] 5061
[11] 5062
[12] 5063
[13] 5064
running/max: 10/10, wait 1s ...
pid: 5060 5061 5062 5063 5064 5055 5056 5057 5058 5059
running/max: 10/10, wait 1s ...
pid: 5060 5061 5062 5063 5064 5055 5056 5057 5058 5059
[11]    done       $*
[5]    done       $*
[5] 5067
[12]    done       $*
[11] 5068
[6]    done       $*
[6] 5069
[12] 5070
running/max: 10/10, wait 1s ...
pid: 5070 5060 5061 5064 5055 5067 5068 5069 5058 5059
[13]  - done       $*
[4]    done       $*
[4] 5072
[13] 5073
running/max: 10/10, wait 1s ...
pid: 5070 5060 5072 5061 5073 5067 5068 5069 5058 5059
[5]    done       $*
[6]    done       $*
[5] 5075
[6] 5076
running/max: 10/10, wait 1s ...
pid: 5070 5060 5072 5061 5073 5075 5076 5068 5058 5059
...

思路：

    需要在全局变量里记录最大进程并发数和当前运行的进程（哈希表）。
    每运行一个进程，将对应的进程号放入哈希表中。
    如果当前运行进程数达到最大进程并发数，则循环检查哈希表里的进程是否退出。

实现：

rr() {
    (($+max_process)) || typeset -g max_process=10
    (($+running_process)) || typeset -gA running_process=()

    [[ $1 == -j<1-> ]] && {
        max_process=${1[3,-1]}
        shift
    }

    (($# == 0)) && {
        for i (${(k)running_process}) {
            [[ -e /proc/$i ]] || unset "running_process[$i]"
        }

        echo "running/max: $#running_process/$max_process"
        (($#running_process > 0)) && echo "pid: ${(k)running_process}"
        return
    }

    while ((1)) {
        local running_process_num=$#running_process

        if (($running_process_num < max_process)) {
            $* &
            running_process[$!]=1
            return
        }

        for i (${(k)running_process}) {
            [[ -e /proc/$i ]] || unset "running_process[$i]"
        }

        (($#running_process == $running_process_num)) && {
            echo "running/max: $running_process_num/$max_process, wait 1s ..."
            echo "pid: ${(k)running_process}"
            sleep 1
        }
    }
}

使用 inotifywait 的版本（无需循环 sleep 等待）：

rr() {
    (($+max_process)) || typeset -gi max_process=10
    (($+running_process)) || typeset -gA running_process=()

    while {getopts j:h arg} {
        case $arg {
            (j)
            ((OPTARG > 0)) && max_process=$OPTARG
            ;;

            (h)
            echo "Usage: $0 [-j max_process] [cmd] [args]"
            return
            ;;
        }
    }

    shift $((OPTIND - 1))

    (($# == 0)) && {
        for i (${(k)running_process}) {
            [[ -e $i ]] || unset "running_process[$i]"
        }

        echo "running/max: $#running_process/$max_process"
        (($#running_process > 0)) && echo "pids:" ${${(k)running_process/\/proc\/}/\/exe}
        return 0
    }

    while ((1)) {
        local running_process_num=$#running_process

        if (($running_process_num < max_process)) {
            $* &
            running_process[/proc/$!/exe]=1
            return
        }

        for i (${(k)running_process}) {
            [[ -e $i ]] || unset "running_process[$i]"
        }

        (($#running_process == $running_process_num)) && {
            echo "wait $running_process_num pids:" ${${(k)running_process/\/proc\/}/\/exe}
            inotifywait -q ${(k)running_process}
        }
    }
}

