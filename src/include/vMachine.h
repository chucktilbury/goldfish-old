#ifndef VMACHINE_H
#define VMACHINE_H

#include "system.h"
#include "values.h"
#include "store.h"
#include "valStack.h"

#define NUM_REGS    16

typedef uint8_t RegNumType;

typedef struct {
    Value registers[NUM_REGS];
    bool nzero;
    VarStore vstore;
    InstrStore istore;
    StrStore sstore;
    ValStack vstack;
    //CallStack cstack;
    const char* fname;
} VM;

#endif