# reversion /250318

1){motion}>
    --- wbe/WBE
    --- hjkl
    --- gg/G/{num}gg

    --- C-u / C-d   - Pgup/down
    --- z t/z/b     - position cursor to screen top/mid/buttom
    --- $ / 0       - line begin/end
    --- ^           - first word
    --- %           - skip quotion({[)


    --- m{reg}      - mark
    --- `{reg}      - turn to mark
    --- ``          - turn back
    --- `.          - turn to last change place
    --- `^          - turn to last insert place


    --- f{arg}      - turn to
    --- t{arg}      - search till
    --- FT          - reversed f/t
    --- , / ;       - do f/F or t/T cmd again 

    --- / / ?       - search the file narrate / reverse
    --- n / N       - do //? cmd again
    --- *           - cmd / current word



2){insert_mode}>
    --- i/I         - I(turn to word begin)
    --- o/O
    --- a/A
    --- s/S

3){basic_edit_command}>
    --- d-delete x-C-x y-yank p-paste
    
    --- .       repeat last cmd
    --- u       undo
    --- C-r     redo



# ori_version

esc	
i   insert
I   insert the front
a   append
A   append the end
o   open a new line
O   open a new line behind
gg  move to first line
G   move to last line
dd  delete current line
.   repeat
u   undo
^r  redo
w   skip next word
e   skip next word end
b   skip prev word
WBE skip blank only

^u      PageUp
^d      PageDown
{}gg    to line {}
zz      set mouse to screen mid
zt      set mouse to screen top
zb      set mouse to screen buttom

f       search this line
t       search this line and stop ahead
FT      search behind
, ;     research ahead/behind
/ ?     search all file ahead/behind
n N     research ahead/behind
*       search current word

m<>     mark <>
`<>     skip to mark<>
``      skip to last skip place
`.      skip to last change place
`^      skip to last insert place
^       skip to line beginning
$       skip to line starter
%       skip from (/[/{//* to )/]/}/*/

c       change
d       delete
y       yank
v       visual

{motion}
    --wbe

{count}{operator}{motion}
