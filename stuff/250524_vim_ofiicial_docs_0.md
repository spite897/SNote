# buildLog
- program: **vim_official_doc**
- from: **vim9.1/docs/help.txt**
- status: **suspend**

--------
 P0: hints
| command          | official statement | addon          |
| -                | -                  | -              |
| :qa!             | get out of vim     | force to exit? |
| CTRL-]           | Jump to a subject  |                |
| CTRL-o or CTRL-t | Jump back          |                |
|                  |                    |                |
--------

## P1: help-context
Prepend something to specify the help returnings.

| WHAT                 | PREPEND   | e.g.              |
| -                    | -         | -                 |
| Normal mode command  | <nothing> | :help x           |
| Visual mode command  | v_        | :help v_u         |
| Inset mode commande  | i_        | :help i_<Esc>     |
| Command-line command | :         | :help :quit       |
| Command-line editing | c_        | :help c_<Del>     |
| Vim command argument | -         | :help -r          |
| Option               | '         | :help 'textwidth' |
| Regular expresion    | /         | :help /[          |

more info [help-summary](<-->) [notation](<-->)
