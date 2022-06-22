
/*
 * This test requires the preprocessor
 */
#include "traps.inc"

int thevar = 123

load r0, 0xdeadbeef
push r0
load r0, thevar
trap PRINTR
pop r0
trap PRINTR
addr_of_the_exit_instr:
exit
