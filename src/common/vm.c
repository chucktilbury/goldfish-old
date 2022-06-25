
#include "common.h"

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

static VM vm;

void initVM()
{
    initInstrStore();
    initValStack();
    initVarStore();
    initStrStore();
    memset(vm.registers, 0, sizeof(vm.registers));
}

void saveVM(const char* fname)
{
    FILE* fp = fopen(fname, "w");
    if(fp == NULL) {
        fprintf(stderr, "fatal error: cannot open output file: %s\n", strerror(errno));
        exit(1);
    }

    size_t nl = strlen(vm.fname)+1;
    fwrite(&nl, sizeof(nl), 1, fp);
    fwrite(vm.fname, sizeof(char), nl, fp);

    saveVarStore(fp);
    saveInstrStore(fp);
    saveStrStore(fp);
    fclose(fp);
}

void loadVM(const char* fname)
{
    FILE* fp = fopen(fname, "r");
    if(fp == NULL) {
        fprintf(stderr, "fatal error: cannot open input file: %s\n", strerror(errno));
        exit(1);
    }

    initVM(vm);

    size_t nl;
    fread(&nl, sizeof(nl), 1, fp);
    vm.fname = _alloc(nl);
    fread((void*)vm.fname, sizeof(char), nl, fp);

    loadVarStore(fp);
    loadInstrStore(fp);
    loadStrStore(fp);
    fclose(fp);
}

void dumpRegs(FILE* outf)
{
    fprintf(outf, "-------- Dump Registers ----------\n");
    for(int i = 0; i < NUM_REGS; i++) {
        fprintf(outf, "    <R%d>\t", i);
        printVal(&vm.registers[i], outf);
        fprintf(outf, "\n");
    }
    fprintf(outf, "-------- end dump ----------\n\n");
}

const char* regToStr(RegNumType reg)
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

const char* getVmName()
{
    return vm.fname;
}

void setVmName(const char* str)
{
    vm.fname = _copy_str(str);
}

Value* getReg(RegNumType num)
{
    return &vm.registers[num];
}

void setReg(RegNumType num, Value* val)
{
    memcpy(&vm.registers[num], val, sizeof(Value));
}

void setFlag(bool val)
{
    vm.nzero = val;
}

bool getFlag()
{
    return vm.nzero;
}