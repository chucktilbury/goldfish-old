#ifndef PRINT_H
#define PRINT_H

#include "system.h"
#include "vMachine.h"
#include "store.h"

void printVal(Value* val, FILE* fp);
void printVar(Index idx, FILE* fp);
void printObj(Index idx, FILE* fp);
void printReg(Value* val, FILE* fp);
#endif