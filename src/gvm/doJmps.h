#ifndef DOJUMPS_H
#define DOJUMPS_H

// #include "vMachine.h"
// #include "values.h"

void doCall(Value* val);
void doJmp(Value* val);
void doBr(Value* val);
void doReturn();

#endif