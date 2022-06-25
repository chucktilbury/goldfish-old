#line 1 "/home/chuck/Src/goldfish/testing/asm/test4.s"

 


#line 1 "/home/chuck/Src/goldfish/src/runtime/traps.inc"

 






#line 6 "/home/chuck/Src/goldfish/testing/asm/test4.s"

int the_value = 123
float test_value = 143.3487

_start:
    nop
    load r0,test_value
    load r1,the_value
    call the_func
    trap  0    
    exit

 
 
the_func:
    push r0      
    load r0,r1   
    trap  0 
    pop r0       
    return

