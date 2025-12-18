### 实例二：寻找不配对的文件

功能：

需要当前目录下有一些 .txt 和 .txt.md5sum 的文件，需要寻找出没有对应的 .md5sum 文件的 .txt 文件。（实际的场景是寻找已经下载完成的文件，未下载完的文件都对应某个带后缀的文件。）

例子：

当前目录的所有文件：

aa.txt
bb.txt
bb.txt.md5sum
cc dd.txt
cc dd.txt.md5sum
ee ff.txt.md5sum
gg.txt
hh ii.txt

需要找出没有对应 .md5sum 的 .txt 文件：
aa.txt
gg.txt
hh ii.txt

思路：

    找到所有 .md5sum 文件，然后把文件名中的 .md5sum 去掉，即为那些需要排除的 .txt 文件（a）。
        所有的文件，排除掉 .m5sum 文件，再排除掉 a，即结果。

        实现：

        #!/bin/zsh

        all_files=(*)
        bad_files=(*.md5sum)
        bad_files+=(${bad_files/.md5sum})

        # 数组差集操作
        echo ${all_files:|bad_files}


