
#include "system.h"
#include "vMachine.h"
#include "registers.h"
#include "values.h"
#include "print.h"

void dumpRegs(VM* vm, FILE* outf)
{
    fprintf(outf, "-------- Dump Registers ----------\n");
    for(int i = 0; i < NUM_REGS; i++) {
        fprintf(outf, "    <R%d>\t", i);
        printVal(&vm->registers[i], outf);
        fprintf(outf, "\n");
    }
    fprintf(outf, "-------- end dump ----------\n\n");
}

const char* regToStr(Register reg)
{
    return (reg == REG_0)? "R0":
            (reg == REG_1)? "R1":
            (reg == REG_2)? "R2":
            (reg == REG_3)? "R3":
            (reg == REG_4)? "R4":
            (reg == REG_5)? "R5":
            (reg == REG_6)? "R6":
            (reg == REG_7)? "R7":
            (reg == REG_8)? "R8":
            (reg == REG_9)? "R9":
            (reg == REG_10)? "R10":
            (reg == REG_11)? "R11":
            (reg == REG_12)? "R12":
            (reg == REG_13)? "R13":
            (reg == REG_14)? "R14":
            (reg == REG_15)? "R15": "UNKNOWN" ;
}