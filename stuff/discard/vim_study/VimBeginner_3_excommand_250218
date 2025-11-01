{command}

:{range}{excommand}{args}
:{range} normal {command}
:{range} global/{pattern}/{excommand}
    ---{range} default this line

{range}
    inc: {address},{address} or {address}
    {address}
        ---{lineno}     0 -- a virtual line
        ---%    last line or whole file
        ---*    current line
        ---/{pattern}/
        ---{address}+n
        ---{visual}

{excommand}
    ---normal {command}
    ---s{pattern}/{string}/{flag}
        substitute {pattern} to {string}
        {flag}
            ---g    do to all pattern
            ---i    ignore Caps
            ---c    ask before replace
            ---n    count pattern nums / no replace
    ---delete{reg} or d{}    d and yank to [x]
    ---yank{}    or y{}
    ---print     or p
    ---copy{address}
    ---move{address}
    ---put[reg]
