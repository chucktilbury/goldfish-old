#ifndef DOCOMP_H
#define DOCOMP_H

// #include "vMachine.h"
// #include "values.h"

void doNot(uint8_t regs);
void doEq(uint8_t regs);
void doNEq(uint8_t regs);
void doLeq(uint8_t regs);
void doGeq(uint8_t regs);
void doLess(uint8_t regs);
void doGtr(uint8_t regs);

#endif