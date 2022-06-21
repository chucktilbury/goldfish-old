#ifndef REGISTERS_H
#define REGISTERS_H

typedef enum {
    REG_0,
    REG_1,
    REG_2,
    REG_3,
    REG_4,
    REG_5,
    REG_6,
    REG_7,
    REG_8,
    REG_9,
    REG_10,
    REG_11,
    REG_12,
    REG_13,
    REG_14,
    REG_15,
} Register;

#define REG(v)  vm->registers[v]
#define RTYPE(v) REG(v).type
#define RDATA(v) REG(v).data
#define RTTS(v) valTypeToStr(RTYPE(v))
#define REG_UINT(v) RDATA(v).unum
#define REG_INT(v) RDATA(v).inum
#define REG_FLOAT(v) RDATA(v).fnum
#define REG_ADDR(v) RDATA(v).addr
#define REG_BOOL(v) RDATA(v).boolean
#define REG_USR(v) RDATA(v).usrtype
#define NZFLAG vm->nzero

const char* regToStr(Register reg);
void dumpRegs(VM* vm, FILE* outf);

#endif