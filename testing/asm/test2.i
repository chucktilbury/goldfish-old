#line 1 "test2.s"

 


#line 1 "../../src/runtime/traps.inc"




#line 6 "test2.s"

int thevar = 123

load r0, 0xdeadbeef
push r0
load r0, thevar
trap  1 
pop r0
trap  1 
addr_of_the_exit_instr:
exit

