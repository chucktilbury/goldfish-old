
#include "doComp.h"
#include "vmErrors.h"
#include "registers.h"

#define __operation(vm, op, left, right) do { \
        switch(RTYPE(left)) { \
            case UINT: \
                switch(RTYPE(right)) { \
                    case UINT: NZFLAG = (REG_UINT(left) op REG_UINT(right)); break; \
                    case INT: NZFLAG = ((int8_t)REG_UINT(left) op REG_INT(right)); break; \
                    case FLOAT: NZFLAG = ((float)REG_UINT(left) op REG_FLOAT(right)); break; \
                    case ADDRESS: NZFLAG = ((uint32_t)REG_UINT(left) op REG_ADDR(right)); break; \
                    case BOOL: NZFLAG = ((bool)REG_UINT(left) op REG_BOOL(right)); break; \
                    case USRTYPE: \
                        runtimeWarning("deferred %s operation on right %s", #op, RTTS(right)); \
                        break; \
                    case ERROR: \
                    case NOTHING: \
                        runtimeError("invalid %s operation on right %s", #op, RTTS(right)); \
                        break; \
                    default: \
                        fatalError("invalid operand type on right: 0x%0X", RTYPE(right)); \
                } \
                break; \
            case INT: \
                switch(RTYPE(right)) { \
                    case UINT: NZFLAG = (REG_INT(left) op (int8_t)REG_UINT(right)); break; \
                    case INT: NZFLAG = (REG_INT(left) op REG_INT(right)); break; \
                    case FLOAT: NZFLAG = ((float)REG_INT(left) op REG_FLOAT(right)); break; \
                    case ADDRESS: NZFLAG = ((uint32_t)REG_INT(left) op REG_ADDR(right)); break; \
                    case BOOL: NZFLAG = ((bool)REG_INT(left) op REG_BOOL(right)); break; \
                    case USRTYPE: \
                        runtimeWarning("deferred %s operation on right %s", #op, RTTS(right)); \
                        break; \
                    case ERROR: \
                    case NOTHING: \
                        runtimeError("invalid %s operation on right %s", #op, RTTS(right)); \
                        break; \
                    default: \
                        fatalError("invalid operand type on right: 0x%0X", RTYPE(right)); \
                } \
                break; \
            case FLOAT: \
                switch(RTYPE(right)) { \
                    case UINT: NZFLAG = (REG_FLOAT(left) op (float)REG_UINT(right)); break; \
                    case INT: NZFLAG = (REG_FLOAT(left) op (float)REG_INT(right)); break; \
                    case FLOAT: NZFLAG = (REG_FLOAT(left) op REG_FLOAT(right)); break; \
                    case ADDRESS: \
                    case BOOL: \
                        runtimeError("comparing %s to %s makes no sense", RTTS(left), RTTS(right)); \
                        break; \
                    case USRTYPE: \
                        runtimeWarning("deferred %s operation on right %s", #op, RTTS(right)); \
                        break; \
                    case ERROR: \
                    case NOTHING: \
                        runtimeError("invalid %s operation on right %s", #op, RTTS(right)); \
                        break; \
                    default: \
                        fatalError("invalid operand type on right: 0x%0X", RTYPE(right)); \
                } \
                break; \
            case ADDRESS: \
                switch(RTYPE(right)) { \
                    case UINT: NZFLAG = (REG_ADDR(left) op (uint32_t)REG_UINT(right)); break; \
                    case INT: NZFLAG = (REG_ADDR(left) op (uint32_t)REG_INT(right)); break; \
                    case ADDRESS: NZFLAG = (REG_ADDR(left) op (uint32_t)REG_ADDR(right)); break; \
                    case FLOAT: \
                    case BOOL: \
                        runtimeError("comparing %s to %s makes no sense", RTTS(left), RTTS(right)); \
                        break; \
                    case USRTYPE: \
                        runtimeWarning("deferred %s operation on right %s", #op, RTTS(right)); \
                        break; \
                    case ERROR: \
                    case NOTHING: \
                        runtimeError("invalid %s operation on right %s", #op, RTTS(right)); \
                        break; \
                    default: \
                        fatalError("invalid operand type on right: 0x%0X", RTYPE(right)); \
                } \
                break; \
            case BOOL: \
                switch(RTYPE(right)) { \
                    case UINT: NZFLAG = (REG_BOOL(left) op (bool)REG_UINT(right)); break; \
                    case INT: NZFLAG = (REG_BOOL(left) op (bool)REG_INT(right)); break; \
                    case FLOAT: \
                    case ADDRESS: \
                    case BOOL: \
                        runtimeError("comparing %s to %s makes no sense", RTTS(left), RTTS(right)); \
                        break; \
                    case USRTYPE: \
                        runtimeWarning("deferred %s operation on right %s", #op, RTTS(right)); \
                        break; \
                    case ERROR: \
                    case NOTHING: \
                        runtimeError("invalid %s operation on right %s", #op, RTTS(right)); \
                        break; \
                    default: \
                        fatalError("invalid operand type on right: 0x%0X", RTYPE(right)); \
                } \
                break; \
            case USRTYPE: \
                runtimeWarning("deferred %s operation on left %s", #op, RTTS(left)); \
                break; \
            case ERROR: \
            case NOTHING: \
                runtimeError("invalid %s operation on left %s", #op, RTTS(left)); \
                break; \
            default: \
                fatalError("invalid operand type on left: 0x%0X", RTYPE(right)); \
        } \
    } while(0)

void doNot(VM* vm, uint8_t regs)
{
    int r = regs & 0x0F;
    switch(RTYPE(r)) {
        case UINT: NZFLAG = (REG_UINT(r) != 0); break;
        case INT: NZFLAG = (REG_INT(r) != 0); break;
        case FLOAT: NZFLAG = (REG_FLOAT(r) != 0); break;
        case BOOL: NZFLAG = (REG_BOOL(r) != 0); break;
        case ADDRESS: NZFLAG = (REG_ADDR(r) != 0); break;

        case USRTYPE:
            runtimeWarning("deferred boolean operation on %s", RTTS(r));
            break;

        case ERROR:
        case NOTHING:
            runtimeError("invalid boolean operation on %s", RTTS(r));
            break;

        default:
            fatalError("invalid operand type: 0x%02X", RTYPE(r));
            break;
    }
}

void doEq(VM* vm, uint8_t regs)
{
    int left = (regs >> 4) & 0x0F,
        right = regs & 0x0F;
    __operation(vm, ==, left, right);
}

void doNEq(VM* vm, uint8_t regs)
{
    int left = (regs >> 4) & 0x0F,
        right = regs & 0x0F;
    __operation(vm, !=, left, right);
}

void doLeq(VM* vm, uint8_t regs)
{
    int left = (regs >> 4) & 0x0F,
        right = regs & 0x0F;
    __operation(vm, <=, left, right);
}

void doGeq(VM* vm, uint8_t regs)
{
    int left = (regs >> 4) & 0x0F,
        right = regs & 0x0F;
    __operation(vm, >=, left, right);
}

void doLess(VM* vm, uint8_t regs)
{
    int left = (regs >> 4) & 0x0F,
        right = regs & 0x0F;
    __operation(vm, <, left, right);
}

void doGtr(VM* vm, uint8_t regs)
{
    int left = (regs >> 4) & 0x0F,
        right = regs & 0x0F;
    __operation(vm, >, left, right);
}
