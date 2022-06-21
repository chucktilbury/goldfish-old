
uint flarp = 0x123
bool eggs = true

some_symbol:
    call symbol2
    push eggs
    push 123
    pop r0
    jmp symbol2
symbol2:
    br symbol3
    load r14, eggs
    exit
symbol3:
