#ifndef PRINT_H
#define PRINT_H

#include "system.h"
#include "vMachine.h"
#include "store.h"

void printVal(Value* val, FILE* fp);
void printVar(VarStore* store, Index idx, FILE* fp);
void printObj(VM* vm, Index idx, FILE* fp);
void printReg(VM* vm, Value* val, FILE* fp);
#endif