#!/usr/bin/zsh

func(){
        #printf "func in  : %s %s\n" "$1" "$2"
        [[ -e $2 ]] || { 
                printf "mkdir %s\n" "$2"
                select i ( Y N ){
                    [[ $i == "Y" ]] && mkdir "$2"
                    break
                }
        }   
        for i ( "$1"/*(/N) ) {
                local j=$2/${i##*/}
                func "$i" "$j"
        }
}

(( $# == 2 )) && func "$1" "$2" || func src dest

(( $# == 1 )) && [[ $1 == "r" ]] && rm -r dest/*

return
