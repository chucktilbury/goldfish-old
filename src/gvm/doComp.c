
// #include "doComp.h"
// #include "vmErrors.h"
// #include "registers.h"

#include "gvm.h"

#define __operation(op, left, right) do { \
        switch(RTYPE(left)) { \
            case UINT: \
                switch(RTYPE(right)) { \
                    case UINT: setFlag(REG_UINT(left) op REG_UINT(right)); break; \
                    case INT: setFlag((int8_t)REG_UINT(left) op REG_INT(right)); break; \
                    case FLOAT: setFlag((float)REG_UINT(left) op REG_FLOAT(right)); break; \
                    case ADDRESS: setFlag((uint32_t)REG_UINT(left) op REG_ADDR(right)); break; \
                    case BOOL: setFlag((bool)REG_UINT(left) op REG_BOOL(right)); break; \
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
                    case UINT: setFlag(REG_INT(left) op (int8_t)REG_UINT(right)); break; \
                    case INT: setFlag(REG_INT(left) op REG_INT(right)); break; \
                    case FLOAT: setFlag((float)REG_INT(left) op REG_FLOAT(right)); break; \
                    case ADDRESS: setFlag((uint32_t)REG_INT(left) op REG_ADDR(right)); break; \
                    case BOOL: setFlag((bool)REG_INT(left) op REG_BOOL(right)); break; \
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
                    case UINT: setFlag(REG_FLOAT(left) op (float)REG_UINT(right)); break; \
                    case INT: setFlag(REG_FLOAT(left) op (float)REG_INT(right)); break; \
                    case FLOAT: setFlag(REG_FLOAT(left) op REG_FLOAT(right)); break; \
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
                    case UINT: setFlag(REG_ADDR(left) op (uint32_t)REG_UINT(right)); break; \
                    case INT: setFlag(REG_ADDR(left) op (uint32_t)REG_INT(right)); break; \
                    case ADDRESS: setFlag(REG_ADDR(left) op (uint32_t)REG_ADDR(right)); break; \
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
                    case UINT: setFlag(REG_BOOL(left) op (bool)REG_UINT(right)); break; \
                    case INT: setFlag(REG_BOOL(left) op (bool)REG_INT(right)); break; \
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

void doNot(uint8_t regs)
{
    int r = regs & 0x0F;
    switch(RTYPE(r)) {
        case UINT: setFlag(REG_UINT(r) != 0); break;
        case INT: setFlag(REG_INT(r) != 0); break;
        case FLOAT: setFlag(REG_FLOAT(r) != 0); break;
        case BOOL: setFlag(REG_BOOL(r) != 0); break;
        case ADDRESS: setFlag(REG_ADDR(r) != 0); break;

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

void doEq(uint8_t regs)
{
    int left = (regs >> 4) & 0x0F,
        right = regs & 0x0F;
    __operation(==, left, right);
}

void doNEq(uint8_t regs)
{
    int left = (regs >> 4) & 0x0F,
        right = regs & 0x0F;
    __operation(!=, left, right);
}

void doLeq(uint8_t regs)
{
    int left = (regs >> 4) & 0x0F,
        right = regs & 0x0F;
    __operation(<=, left, right);
}

void doGeq(uint8_t regs)
{
    int left = (regs >> 4) & 0x0F,
        right = regs & 0x0F;
    __operation(>=, left, right);
}

void doLess(uint8_t regs)
{
    int left = (regs >> 4) & 0x0F,
        right = regs & 0x0F;
    __operation(<, left, right);
}

void doGtr(uint8_t regs)
{
    int left = (regs >> 4) & 0x0F,
        right = regs & 0x0F;
    __operation(>, left, right);
}
