#ifndef VALSTACK_H
#define VALSTACK_H

#include "common.h"

void initValStack();

void pushValStack(Value* value);
Value* peekValStack(int index);
Value* popValStack();
uint32_t valStackIndex();

#endif
