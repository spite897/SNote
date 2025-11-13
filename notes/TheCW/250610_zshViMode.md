#Plog
- program: **zshViMode** 
- status: **done** 
  
-----------------------------------------------------------------------------
write below to switch emacs mode to vi mode

```zsh
#~/.zshrc
bindkey -v
```

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
To remap keys 

```zsh
#~/.zshrc
bindkey -M vimcmd <key> <mappings>
```

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
add this function to make ur cursor be I-beam-form in insert mode , when in 
vi-mode switch to Block-form.

```zsh
#~/.zshrc
function zle-keymap-select {
    if [[ ${KEYMAP} == vicmd ]] || [[ $1 = 'block' ]]; then
        echo -ne '\e[1 q'
    elif [[ ${KEYMAP} == main ]] || [[ ${KEYMAP} == viins ]] || [[ ${KEYMAP} = '' ]] || [[ $1 = 'beam' ]]; then
        echo -ne '\e[5 q'
    fi
}
zle -N zle-keymap-select

echo -ne '\e[5 q'
```
