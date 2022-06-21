
/*
 * This test requires the preprocessor
 */
#include "traps.inc"

int thevar = 123

load r0, thevar
trap PRINTR
addr_of_the_exit_instr:
exit
