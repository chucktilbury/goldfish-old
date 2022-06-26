
S#include "gvm.h"

int runLoop()
{
    bool finished = false;
    uint8_t op;
    int retv = 0;

    while(!finished) {
        if(getErrors() > 0) {
            finished = true;
            retv = -getErrors();
            continue;
        }
        READ_VM_OBJ(uint8_t, op);

        switch(op) {

            // exit the VM with a error.
            case OP_ABORT: {
                    // Immediate is a VarIdx
                    fprintf(stderr, "runtime error: abort instruction: ");
                    Index idx;
                    READ_VM_OBJ(Index, idx);
                    printVal(getVar(idx), stderr);
                    fprintf(stderr, "\n");
                    finished = true;
                    retv = -1;
                }
                break;

            case OP_ABORTI: {
                    // immediate is a Value
                    fprintf(stderr, "runtime error: abort instruction: ");
                    Value val;
                    READ_VM_OBJ(Value, val);
                    printVal(&val, stderr);
                    fprintf(stderr, "\n");
                    finished = true;
                    retv = -1;
                }
                break;

            case OP_ABORTR: {
                    // immediate is a register
                    fprintf(stderr, "runtime error: abort instruction: ");
                    uint8_t reg;
                    READ_VM_OBJ(uint8_t, reg);
                    finished = true;
                    printVal(getReg(reg), stderr);
                    fprintf(stderr, "\n");
                    retv = -1;
                }
                break;


            case OP_EXIT:
                // exit with no error
                //printf("exiting\n");
                finished = true;
                retv = 0;
                break;

            case OP_NOP:
                // do nothing
                break;

            case OP_CALL: {
                    // operand is a Value index
                    Index idx;
                    READ_VM_OBJ(Index, idx);
                    doCall(getVar(idx));
                }
                break;

            case OP_CALLI:{
                    // operand is an immediate Value
                    Value val;
                    READ_VM_OBJ(Value, val);
                    doCall(&val);
                }
                break;

            case OP_CALLR:{
                    // operand is a single register
                    uint8_t reg;
                    READ_VM_OBJ(uint8_t, reg);
                    doCall(getReg(reg));
                }
                break;

            case OP_TRAP: {
                    // operand is a uint16_t
                    TrapNumType tno;
                    READ_VM_OBJ(TrapNumType, tno);
                    doTrap(tno);
                }
                break;

            case OP_RETURN: {
                    // no operands
                    doReturn();
                }
                break;

            case OP_JMP:{
                    // operand is a Value index
                    Index idx;
                    READ_VM_OBJ(Index, idx);
                    doJmp(getVar(idx));
                }
                break;

            case OP_JMPI:{
                    // operand is an immediate Value
                    Value val;
                    READ_VM_OBJ(Value, val);
                    doJmp(&val);
                }
                break;

            case OP_JMPR:{
                    // operand is a single register
                    RegNumType reg;
                    READ_VM_OBJ(RegNumType, reg);
                    doJmp(getReg(reg));
                }
                break;

            case OP_BR:{
                    // operand is a Value Index
                    Index idx;
                    READ_VM_OBJ(Index, idx);
                    doBr(getVar(idx));
                }
                break;

            case OP_BRI: {
                    // operand is an immediate Value
                    Value val;
                    READ_VM_OBJ(Value, val);
                    doBr(&val);
                }
                break;

            case OP_BRR: {
                    // operand is a single register
                    RegNumType reg;
                    READ_VM_OBJ(RegNumType, reg);
                    doBr(getReg(reg));
                }
                break;

            case OP_PUSH: {
                    // operand is a Value index
                    Index idx;
                    READ_VM_OBJ(Index, idx);
                    pushValStack(getVar(idx));
                }
                break;

            case OP_PUSHI: {
                    // operand is an immediate Value
                    Value val;
                    READ_VM_OBJ(Value, val);
                    pushValStack(&val);
                }
                break;

            case OP_PUSHR: {
                    // operand is a single register
                    RegNumType reg;
                    READ_VM_OBJ(RegNumType, reg);
                    pushValStack(getReg(reg));
                }
                break;

            case OP_POP: {
                    // operand is a single register
                    uint8_t reg;
                    READ_VM_OBJ(uint8_t, reg);
                    setReg(reg, popValStack());
                }
                break;

            case OP_LOAD: {
                    // operand is a single register
                    // operand is a Value index
                    RegNumType reg;
                    READ_VM_OBJ(RegNumType, reg);
                    Index idx;
                    READ_VM_OBJ(Index, idx);
                    setReg(reg, getVar(idx));
                }
                break;

            case OP_LOADI: {
                    // operand is a single register
                    // operand is an immediate Value
                    RegNumType reg;
                    READ_VM_OBJ(RegNumType, reg);
                    Value val;
                    READ_VM_OBJ(Value, val);
                    setReg(reg, &val);
                }
                break;

            case OP_LOADR: {
                    // operand is 2 registers
                    RegNumType regs;
                    READ_VM_OBJ(RegNumType, regs);
                    //vm->registers[(regs >> 4) & 0xF] = vm->registers[regs & 0xF];
                    setReg((regs >> 4) & 0xF, getReg(regs & 0xF));
                }
                break;

            case OP_STORE: {
                    // operand is a Value index
                    // operand is a single register
                    Index idx;
                    READ_VM_OBJ(Index, idx);
                    RegNumType reg;
                    READ_VM_OBJ(RegNumType, reg);
                    assignVar(idx, getReg(reg)); //vm->registers[reg]);
                }
                break;

            case OP_NOT: {
                    // operand is single register (result in zero flag)
                    RegNumType reg;
                    READ_VM_OBJ(RegNumType, reg);
                    doNot(reg);
                }
                break;

            case OP_EQ: {
                    // operand is 2 registers (result in zero flag)
                    RegNumType regs;
                    READ_VM_OBJ(RegNumType, regs);
                    doEq(regs);
                }
                break;

            case OP_NEQ: {
                    // operand is 2 registers (result in zero flag)
                    RegNumType regs;
                    READ_VM_OBJ(RegNumType, regs);
                    doNEq(regs);
                }
                break;

            case OP_LEQ: {
                    // operand is 2 registers (result in zero flag)
                    RegNumType regs;
                    READ_VM_OBJ(RegNumType, regs);
                    doLeq(regs);
                }
                break;

            case OP_GEQ: {
                    // operand is 2 registers (result in zero flag)
                    RegNumType regs;
                    READ_VM_OBJ(RegNumType, regs);
                    doGeq(regs);
                }
                break;

            case OP_LESS: {
                    // operand is 2 registers (result in zero flag)
                    RegNumType regs;
                    READ_VM_OBJ(RegNumType, regs);
                    doLess(regs);
                }
                break;

            case OP_GTR: {
                    // operand is 2 registers (result in zero flag)
                    RegNumType regs;
                    READ_VM_OBJ(RegNumType, regs);
                    doGtr(regs);
                }
                break;

            case OP_NEG: {
                    // operand is 2 registers
                    RegNumType regs;
                    READ_VM_OBJ(RegNumType, regs);
                    doNeg(regs);
                }
                break;

            case OP_ADD: {
                    // operand is 3 registers
                    uint16_t regs;
                    READ_VM_OBJ(uint16_t, regs);
                    doAdd(regs);
                }
                break;

            case OP_SUB: {
                    // operand is 3 registers
                    uint16_t regs;
                    READ_VM_OBJ(uint16_t, regs);
                    doSub(regs);
                }
                break;

            case OP_MUL: {
                    // operand is 3 registers
                    uint16_t regs;
                    READ_VM_OBJ(uint16_t, regs);
                    doMul(regs);
                }
                break;

            case OP_DIV: {
                    // operand is 3 registers
                    uint16_t regs;
                    READ_VM_OBJ(uint16_t, regs);
                    doDiv(regs);
                }
                break;

            case OP_MOD: {
                    // operand is 3 registers
                    uint16_t regs;
                    READ_VM_OBJ(uint16_t, regs);
                    doMod(regs);
                }
                break;

            default:
                fprintf(stderr, "runtime error: Unknown instruction: 0x%02X\n", op);
                finished = true;
                retv = -2;
                break;
        }

        // exit if there are no more instructions
        finished = (finished == false)? isInstrEnded(): true;
    }

    return retv;
}
