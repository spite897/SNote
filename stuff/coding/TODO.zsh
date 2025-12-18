#!/usr/bin/zsh

for i ( **/test ) { 
    recv=0

    printf "mkdir -p \".test/%s\"\n" "${i/test}"
    printf "Confirm (Y/n) : " 
    read recv
    if [[ $recv == "Y" || $recv == "y" ]] {
        src=$i
        dest=".test/${i/test}"

        mkdir -p $dest
        mv $src/* $dest
        ln -rs $dest ${src/test}
        rm -r $src
    }
    
    
    
}
