#!/usr/bin/zsh


main(){
    for i ( $*[2,-1] ){
        l="$(echo $i | sed $1)"
        [[ $i == $l ]] && continue
        mv -v $i $l
    }

}




(( $# == 0 )) && main s/aaa/bbb/g src/**/*(.) \
          || if [[ $1 == "r" ]] {
                rm -rf src
                mkdir -p src/xxx
                tmp=(src/{aaa_aaa.txt,ccc.txt,"xxx/aaa bbb.txt","xxx/bbb ccc.txt"})
                touch $tmp
          } else {
                main $*
          }   
