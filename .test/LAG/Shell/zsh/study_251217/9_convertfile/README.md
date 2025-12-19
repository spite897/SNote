
实例九：批量转换图片格式

功能：

将当前目录及子目录的所有常见图片格式转换成 jpg 格式（jpg 格式也要转换一遍，可以减少文件体积），然后删除原图片。需要用 5 个并发进程来处理。注意避免仅扩展名不同的文件互相覆盖的情况。

例子：

% tree
.
├── mine
│   ├── 信.txt
│   ├── 第一封信.jpg
│   └── 第二封信.JPG
├── 搞笑
│   ├── 卖萌.GIF
│   ├── 猫吃鱼.gif
│   └── 猫抢东西吃.gif
└── 素材
    ├── 104 按键模板.jpg
    ├── 104 按键模板.psd
    ├── ahk
    │   ├── ahk_bg.jpg
    │   ├── ahk_home_logo.jpg
    │   ├── ahk_home_logo.txt
    │   ├── ahk_home_qr.jpg
    │   ├── ahk_home_qr_small.jpg
    │   └── ahk_logo.png
    ├── stp_fc_cw_png_pk
    │   ├── HD.PNG
    │   ├── newimage.png
    │   ├── nshd.PNG
    │   └── std.png
    ├── 地球.jpg
    ├── 星系.JPEG
    ├── 木纹 背景.GIF
    ├── 木纹 背景.jpeg
    └── 木纹 背景.jpg

5 directories, 23 files

% alltojpg
running/max: 0/5
running: 5, wait 1.0000000000s ...
pid: 5953 5954 5955 5956 5957
running: 5, wait 1.0000000000s ...
pid: 5965 5966 5967 5968 5959

% tree
.
├── mine
│   ├── 信.txt
│   ├── 第一封信.jpg
│   └── 第二封信.jpg
├── 搞笑
│   ├── 卖萌_g.jpg
│   ├── 猫吃鱼_g.jpg
│   └── 猫抢东西吃_g.jpg
└── 素材
    ├── 104 按键模板.jpg
    ├── 104 按键模板.psd
    ├── ahk
    │   ├── ahk_bg.jpg
    │   ├── ahk_home_logo.jpg
    │   ├── ahk_home_logo.txt
    │   ├── ahk_home_qr.jpg
    │   ├── ahk_home_qr_small.jpg
    │   └── ahk_logo_p.jpg
    ├── stp_fc_cw_png_pk
    │   ├── HD_p.jpg
    │   ├── newimage_p.jpg
    │   ├── nshd_p.jpg
    │   └── std_p.jpg
    ├── 地球.jpg
    ├── 星系_e.jpg
    ├── 木纹 背景_e.jpg
    ├── 木纹 背景_g.jpg
    └── 木纹 背景.jpg

5 directories, 23 files

思路：

    并发运行命令的方法见上一个实例。
    转换图片格式用 gm convert 命令（graphicsmagick 中）或者 convert 命令（imagemagick 中）。
    常见的图片文件扩展名有 jpg jpeg png gif，另外可能是大写的扩展名。
    为了避免类似 a.gif 覆盖 a.jpg 的情况，为不同的文件格式添加不同后缀，这样可以无需检查是否有同名文件，加快速度。

实现：

#!/bin/zsh

# rr 是上一个实例中的代码
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


# JPG 作为中间扩展名
rename .JPG .jpg **/*.JPG

# 设置进程并发数为 5
rr -j5

for i (**/*.(jpg|png|PNG|jpeg|JPEG|gif|GIF)) {
    rr gm convert $i $i.JPG
}

# 等所有操作结束
wait

# 删除原文件
rm **/*.(jpg|png|PNG|jpeg|JPEG|gif|GIF)

# 避免覆盖同名文件
rename .jpg.JPG .jpg **/*.JPG
rename .png.JPG _p.jpg **/*.JPG
rename .PNG.JPG _p.jpg **/*.JPG
rename .jpeg.JPG _e.jpg **/*.JPG
rename .JPEG.JPG _e.jpg **/*.JPG
rename .gif.JPG _g.jpg **/*.JPG
rename .GIF.JPG _g.jpg **/*.JPG

