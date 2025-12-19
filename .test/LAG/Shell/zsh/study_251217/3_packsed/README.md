
### 实例三：用 sed 批量重命名文件

功能：

用形如 sed 命令的用法批量重命名文件。

例子：

- 实现 renamex 命令，接受的第一个参数为 sed 的主体参数，其余参数是文件列表
- 效果是根据 sed 对文件名的修改重命名这些文件

% tree
.
├── aaa_aaa.txt
├── aaa.txt
├── ccc.txt
└── xxx
    ├── aaa bbb.txt
    └── bbb ccc.txt

% renamex s/aaa/bbb/g **/*
'aaa_aaa.txt' -> 'bbb_bbb.txt'
'aaa.txt' -> 'bbb.txt'
'xxx/aaa bbb.txt' -> 'xxx/bbb bbb.txt'

% tree
.
├── bbb_bbb.txt
├── bbb.txt
├── ccc.txt
└── xxx
    ├── bbb bbb.txt
    └── bbb ccc.txt

思路：

    要找出所有的文件名，然后用 sed 替换成新文件名。
    如果文件名有变化，用 mv 命令移动

实现：

#!/bin/zsh

(($+2)) || {
    echo 'Usage: renamex s/aaa/bbb/g *.txt'
    return
}

for name ($*[2,-1]) {
    local new_name="$(echo $name | sed $1)"
    [[ $name == $new_name ]] && continue
    mv -v $name $new_name
}

