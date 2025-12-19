#!/usr/bin/zsh

local -A TRANSI_TABLE=(
        零 "+0"
        一 "+1"
        二 "+2"
        三 "+3"
        四 "+4"
        五 "+5"
        六 "+6"
        七 "+7"
        八 "+8"
        九 "+9"
        十 "*10"
        百 "*100"
)

[[ $1 == "十" ]] && in="一十" || in=$1
out=""

for i ({1..$#in}) { 
    out+=$TRANSI_TABLE[$in[$i]]
}

echo $(( $out ))
