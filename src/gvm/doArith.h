#ifndef DOARITH_H
#define DOARITH_H

// #include "vMachine.h"
// #include "values.h"

void doNeg(uint8_t regs);
void doAdd(uint16_t regs);
void doSub(uint16_t regs);
void doMul(uint16_t regs);
void doDiv(uint16_t regs);
void doMod(uint16_t regs);

#endif