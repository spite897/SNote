{textobjects}
format: i/a + wWsp or ({[
    --i -> inner
    --a -> a (include blocks or {[ )

{count}{operator}{textobjects}

gu  upper char
gU  lower char
g~  reverse upper and lower

J   join two lines
^a  find next number and ++
^x                       --

{visual} g ^A   turn 1.1.1. to 1.2.3.

v{motion}
v{textobjects}  select certain area

{register}
"{register}     select target register
a-z replace     A-Z append
exmp:   "adaw   "ayy    "ap

{marco}
q{register} ... q
make a marco    (2nd q as end)
@{register}
use marco
@@  repeat

"%  file_name
".  last insert text
":  last command
""  yank delete text
