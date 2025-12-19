
实例五：转换 100 以内的汉字数字为阿拉伯数字

功能：

转换 100 以内的汉字数字为阿拉伯数字，如六十八转换成 68。

思路：

    建一个哈希表存放汉字与数字的对应关系。
    比较麻烦的是“十”，在不同的位置，转换成的数字不同，需要分别处理。

实现：

#!/bin/zsh

local -A table=(
零 0
一 1
二 2
三 3
四 4
五 5
六 6
七 7
八 8
九 9
)

local result

if [[ $1 == 十 ]] {
    result=一零
} elif [[ $1 == 十* ]] {
    result=${1/十/一}
} elif [[ $1 == *十 ]] {
    result=${1/十/零}
} elif [[ $1 == *十* ]] {
    result=${1/十}
} else {
    result=$1
}

for i ({1..$#result}) {
    result[i]=$table[$result[i]]

    if [[ -z $result[i] ]] {
        echo error
        return 1
    }
}

echo $result

运行结果：

% ./convert 一
1
% ./convert 十
10
% ./convert 十五
15
% ./convert 二十
20
% ./convert 五十六
56
% ./convert 一百
error

