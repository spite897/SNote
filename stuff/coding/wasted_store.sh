: '
這是一個用來把不同目錄下的.wasted目錄集中到相對根目錄下的.wasted目錄並創建相對鏈接
)PS : 死Shell怎麼這麼難
'

func(){
    for dir in $( ls -a $1) ; do
        if [[ $dir = .wasted ]] ;then
            printf "Find : %s%s\n" $1 $dir

            dir1=$1
            dir1=${dir1//[^\/]/}
            dir1=${dir1//\//..\/}
            dir1="${dir1}.wasted/${1}"

            dir2="${1}"

            #dir1=${dir1//[^\.]/\/}
            #dir1=${dir1///*/}
            #dir1=${dir1/[^\/]\//..\/}

            printf "ln -s %s %s\n" $dir1 $dir2
            read -p "Confirm [Y/n] : " recv
            if [[ $recv = "y" || $recv = "Y" ]] ; then
                mkdir ".wasted/${dir2}" -p
                ln -s $dir1 "${dir2}tmp"
                tmp="${dir2}.wasted/*"
                mv -t ".wasted/${dir2}" $tmp

                rm -r "${dir2}.wasted"
                mv  "${dir2}tmp" "${dir2}.wasted"

            else
                printf "canceled\n"
            fi
        fi
    done
}
# 未實現
check(){
    for dir in $( ls -A $1) ; do
            if [[ -d $dir ]] && [[  -L $dir ]] ; then
            if [[ $dir = .wasted ]] ;then
                link "${1}/" "${dir}/"
            else 
                echo $dir
                check $dir
            fi
        fi
    done
}

# 輸入請用 direct/ 形式
func $1

: '
git restore notes/TheCW
rm .wasted/notes -r
rm notes/TheCW/tmp
'
