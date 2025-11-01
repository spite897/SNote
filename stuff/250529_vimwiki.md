# buildLog
- program: **vimwiki** 
- from: **doc/vimwiki** 
- status: **building** 
  
-----------------------------------------------------------------------------
### P0: profile

- usage
  - organize notes and ideas
  - manage todo-lists
  - write documentation
  - maintain a diary
  - export your documents to HTML

-----------------------------------------------------------------------------
### P1: starter `1-2`

change your wiki syntax to **Markdown** .

```vim
let g:vimwiki_list = [{'path': '~/vimwiki/', 
        \ 'syntax': 'markdown', 'ext': '.md'}]
```

1. **global mappings** 

| keymaps              | function             | note |
| -                    | -                    | -    |
| **General Part**     | -                    | -    |
| \<Leader>ww          | enter vimwiki        |      |
| \<Leader>wt          | do ~ in new tab      |      |
| \<Leader>ws          | list and select      |      |
| **Diary Part**       | -                    | -    |
| \<Leader>wi          | enter diary wiki     |      |
| \<Leader>w\<Leader>t | do ~ in new tab      |      |
| \<Leader>w\<Leader>w | make daily diary     |      |
| \<Leader>w\<Leader>y | make yesterday diary |      |
| \<Leader>w\<Leader>m | make tomorrow diary  |      |

2. **local mappings** 

| keymaps              | function                  | note       |
| -                    | -                         | -          |
| **General Part**     | -                         | -          |
| \<Leader>wn          | new wiki                  |            |
| \<Leader>wd          | delete current wiki       |            |
| \<Leader>wr          | rename current wiki       |            |
| **Visual Part**      | -                         | -          |
| \<Leader>wh          | .wiki to HTML             | .wiki only |
| \<Leader>whh         | ~ and open                |            |
| \<Leader>w\<Leader>i | update diary section      |            |
| **Edit Part**        | -                         | -          |
| \<Backspace>         | jump back                 | \<Ctrl-o>  |
| \<Tab>               | next link                 |            |
| \<S-Tab>             | prev link                 |            |
| \<CR>                | make a link               |            |
| \<S-CR>              | split and ~               |            |
| \<C-CR>              | vsplit and ~              |            |
| \<M-CR>              |                           |            |
| \<C-S-CR>            |                           |            |
| \<Leader>wc          | colorize visual selection |            |


> - *\<Leader>* is defaultly **\\** .
> - use **visual mode** to make a multiple words link
> - use *<count>* 
> - make sure following settings on for Vimwiki working  
>   ```vim
>   set nocompatible
>   filetype plugin on
>   syntax on
>   ```

-----------------------------------------------------------------------------
### P2: Links

Plain links 
> - [[This is a link]]
> - [[This is a link source|Description of the link]]

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
### For the directory
- "/" is considered the wiki root
- "." is current index
- "//" is absolute path

-----------------------------------------------------------------------------

> TODO :
> - <silent> <buffer>
