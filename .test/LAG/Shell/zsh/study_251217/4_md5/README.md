
实例四：根据文件的 md5 删除重复文件

功能：

删除当前目录以及子目录下所有的重复文件（根据 md5 判断，不是很严谨）。

思路：

    用 md5sum 命令计算所有文件的 md5。
    使用哈希表判断 md5 是否重复，删除哈希表里已经有 md5 的后续文件。

实现：

#!/bin/zsh

# D 是包含以 . 开头的隐藏文件
local files=("${(f)$(md5sum **/*(.D))}")
local files_to_delete=()
local -A md5s

for i ($files) {
    # 取前 32 位，即 md5 的长度
    local md5=$i[1,32]

    if (($+md5s[$md5])) {
        # 取 35 位之后的内容，即文件路径，md5 后边有两个空格
        files_to_delete+=($i[35,-1])
    } else {
        md5s[$md5]=1
    }
}

(($#files_to_delete)) && rm -v $files_to_delete

