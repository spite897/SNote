# buildLog
- program: **Shell_zsh_basis** 
- status: **building** 

-----------------------------------------------------------------------------

```zsh
# 支持多種語法

if <condition> {
}elif{}
else{}

while <condition>{}

for i (<array>){}

case $i {
    (a)
    <cmd>
    ;;
    
    (b)
    ...
    ;&
    # 執行下一個
    
    (c)
    ...
    ;|
    # 判斷下一個
    
    (*)
    ...
    ;;
}

select i (aa bb cc){
    ...
}
# 用戶輸入語句 
```

`[[..]]` 用於字符串比較;
`((..))` 用於數值比較;
`{..}` 用於運行命令;
`(..)` 用於在子shell中運行命令;

> - zsh 使用 `%` 作爲命令提示符
> - zsh 支持浮點數類型 相比於bash
> - zsh 單引號可以使用轉義字符

-----------------------------------------------------------------------------

### 字符串操作

```zsh
echo $str[(I)ab]
# 从右往左匹配 "ab" 失败返回0 返回索引
echo $str[(i)ab]
# 反之 失败返回 $#str+1 返回索引
##  对数组同样有效

echo ${str:#ab}
# str匹配则输出空 反之输出 $str
echo ${(M)str:#ab}
# 反转输出

str[n]=
# 删除指定索引或区间
str[n]=2345
# 不定长替换

(($+str))
# 检查变量是否定义

${(U)str}   || ${str:u}
${(L)str}   || ${str:l}
${(C)str}
# 大写/小写/首字母大写其余小写

${str:h}    # 目录名 最后 / 之前部分 或 .
${str:t}    # 文件名 最后 / 之后部分 或 $str
${str:e}    # 拓展名 最后 . 之后部分 或 空
${str:r}    # 去除拓展名
${(q)str}   # 为特殊字符添加转义符

${str:A}    # 相对路径转绝对路径

${str[(w)2]}    # 使用空格作为分隔符 的第2个字符
${str[(s:--:)]}   # 指定分隔符 返回数组
${(f)str}       # 使用换行符分割

${=str}         # 使用空格作为分隔符 返回数组
$IFS            # 使用此环境变量作为分隔符

str=$(<filename)
echo "$(<filename)"
# 性能超过 cat

echo ${"$(<filename)"[(f)2]}        # 第二行
echo ${"$(<filename)"[(fr)*ars*]}   # 包含 ars 第一行
# 在读取小文件和频繁调用时性能超过 sed

wc -l <(ps)     # 返回 fd 路径 可能报错
wc -l =(ps)     # 临时文件

```

> - zsh 支持數組截取及負索引 `str[2,-1]`
> - `print -r` 忽视转义字符

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

### 关于 print 命令

- -l        : 分行输出多个参数
- -n        : 不添加换行符
- -m <arg>  : 只输出匹配的参数
- -o/O      : 升序/降序排列
- -i        : 对大小写不敏感
- -r        : 不进行转义
- -c / -C n : 竖向排列输出 -C 指定列数
- -D        : 转化为相对家目录的路径
- -N        : 输出以 null (\x00) 分割
- -x n      : 将行首的 tab 替换为 n 个空格
- -X n      : 制表 通过 tab
- -u arg    : 指定文件描述符
- -v arg    : 将输出保存到变量 arg 
- -s/S      : 输出到 history ; -s 可接受多个参数
- -z        : 输出到命令行编辑区
- -f        : 格式化输出
- -P        : 输出带颜色和特殊样式的字符串
- -b        : 辨认 bindkey 中的转义字符串
- -R        : 模拟 echo 命令 仅支持 -n 与 -e 选项

### 关于 输出带颜色和特殊样式的字符串

%B...[%b]       : 加粗
%U...[%u]       : 下划线
%S...[%s]       : 反色
%F{<color}...%f : 前景色
%K{<color}...%k : 后景色

> **关于颜色**
> - black=1, red, green, yellow, blue, magenta, cyan, white

### 关于格式化输出

 -- print format specifier --
       -- leave one space in front of positive number from signed conversion
       -     -- left adjust result
       -     .     -- precision
       -     '     -- thousand separators
       -     *     -- field width in next argument
       -     #     -- alternate form
       -     %     -- a percent sign
       -     +     -- always place sign before a number from signed conversion
       -     0     -- zero pad to length
       -     b     -- as %s but interpret escape sequences in argument
       -     c     -- print the first character of the argument
       -     E  e  -- double number in scientific notation
       -     f     -- double number
       -     G  g  -- double number as %f or %e depending on size
       -     i  d  -- signed decimal number or with leading " numeric value of following character
       -     n     -- store number of printed bytes in parameter specified by argument
       -     o     -- unsigned octal number
       -     q     -- as %s but shell quote result
       -     s     -- print the argument as a string
       -     u     -- unsigned decimal number
       -     X  x  -- unsigned hexadecimal number, letters capitalized as x
       - 

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

### 关于 通配符

- ?     : 任意一个字符
- [..]  : 其中的一个字符 同正则
- <n-n> : 匹配一个整数 默认上下界是无穷大与无穷小
- (..|..) : 或符号

> zsh 支持 extended_glob
       
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

### 关于 数组

```zsh
$array[(I)ars]
$array[(o)ars]
${(on)array}
# 按数值大小
${(Oa)array}
# 倒序
${(u)array}
# 除去重复

a=(a{b,c,d})
# =>
a=(ab ac ad)
# 这个功能bash也有

${array1:*array2}   # 取交集 不会去重
${array1:|array2}   # 取差集 1-2
${array1:^array2}   # 交叉合并 1[1] 2[1] 1[2] ... 直到一个数组元素用尽
${array1:^^array2}  # 短数组会从头 直到所有元素都加入后

# 对每个元素进行字符串操作
${array:t}
${array:e}
# ...
${array/a/t}
${array:#a*}
```

> - `array+=ars`    : 添加元素 或拼接数组
> - zsh 支持數組截取及負索引 `str[2,-1]`
> - zsh 数组索引从1开始计算
 
-----------------------------------------------------------------------------
