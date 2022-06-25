#ifndef VM_H
#define VM_H

#define NUM_REGS    16

typedef uint8_t RegNumType;

typedef struct {
    Value registers[NUM_REGS];
    bool nzero;
    // VarStore vstore;
    // InstrStore istore;
    // StrStore sstore;
    // ValStack vstack;
    //CallStack cstack;
    const char* fname;
} VM;

#endif