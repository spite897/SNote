#!/usr/bin/zsh

: "
通过表的写法既不优雅也不高效
"

EXT=".md5sum"

main(){
        local -A table       
        for i ($1/*(.)) {
                table[$i]=true
        }
        for i ($1/*$EXT(.)) {
                unset "table[${i}]"
                unset "table[${i%$EXT}]"
        }
        print -l ${(k)table}
}

# 非常zsh 的写法
_main(){
        all_files=($1/*)
        bad_files=($1/*$EXT)
        bad_files+=(${bad_files/$EXT})

        echo ${all_files:|bad_files}
}

(( ${+1} )) && main $1 || main src

return
