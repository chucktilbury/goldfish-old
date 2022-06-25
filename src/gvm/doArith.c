
#include <math.h>
// #include "doArith.h"
// #include "vmErrors.h"
// #include "registers.h"

#include "gvm.h"

#define _verify(v) do { \
    switch(RTYPE(v)) { \
        case UINT: \
            if(REG_UINT(v) == 0) \
                runtimeError("divide by zero error"); \
            break; \
        case INT: \
            if(REG_INT(v) == 0) \
                runtimeError("divide by zero error"); \
            break; \
        case FLOAT: \
            if(REG_FLOAT(v) == 0) \
                runtimeError("divide by zero error"); \
            break; \
        default: \
            break; \
    } \
} while(0)

//static inline void operation(VM* vm, const char* op, UINT_t dest, UINT_t left, UINT_t right)
#define _operation(op, dest, left, right) do { \
    switch(RTYPE(left)) { \
        case UINT: { \
                switch(RTYPE(right)) { \
                    case UINT: \
                        RTYPE(dest) = UINT; \
                        REG_UINT(dest) = REG_UINT(left) op REG_UINT(right); \
                        break; \
                    case INT: \
                        RTYPE(dest) = INT; \
                        REG_INT(dest) = REG_UINT(left) op REG_INT(right); \
                        break; \
                    case FLOAT: \
                        RTYPE(dest) = FLOAT; \
                        REG_FLOAT(dest) = REG_UINT(left) op REG_FLOAT(right); \
                        break; \
                    case ADDRESS: \
                        RTYPE(dest) = ADDRESS; \
                        REG_ADDR(dest) = REG_UINT(left) op REG_ADDR(right); \
                        break; \
                    case USRTYPE: \
                        runtimeWarning("defer operation for %s %s %s\n", RTTS(left), #op, RTTS(right)); \
                        break; \
                    case ERROR: \
                    case NOTHING: \
                    case BOOL: \
                        runtimeError("operation on %s %s %s is invalid\n", RTTS(left), #op, RTTS(right)); \
                        break; \
                    default: \
                        fatalError("invalid right hand type: 0x%02X", RTYPE(right)); \
                        break; \
                } \
            } \
            break; \
        case INT: { \
                switch(RTYPE(right)) { \
                    case UINT: \
                        RTYPE(dest) = INT; \
                        REG_INT(dest) = REG_INT(left) op REG_UINT(right); \
                        break; \
                    case INT: \
                        RTYPE(dest) = INT; \
                        REG_INT(dest) = REG_INT(left) op REG_INT(right); \
                        break; \
                    case FLOAT: \
                        RTYPE(dest) = FLOAT; \
                        REG_FLOAT(dest) = REG_INT(left) op REG_FLOAT(right); \
                        break; \
                    case ADDRESS: \
                        RTYPE(dest) = ADDRESS; \
                        REG_ADDR(dest) = REG_INT(left) op REG_ADDR(right); \
                        break; \
                    case USRTYPE: \
                        runtimeWarning("defer operation for %s %s %s\n", RTTS(left), #op, RTTS(right)); \
                        break; \
                    case ERROR: \
                    case NOTHING: \
                    case BOOL: \
                        runtimeError("operation on %s %s %s is invalid\n", RTTS(left), #op, RTTS(right)); \
                        break; \
                    default: \
                        fatalError("invalid right hand type: 0x%02X", RTYPE(right)); \
                        break; \
                } \
            } \
            break; \
        case FLOAT: { \
                switch(RTYPE(right)) { \
                    case UINT: \
                        RTYPE(dest) = FLOAT; \
                        REG_FLOAT(dest) = REG_FLOAT(left) op REG_UINT(right); \
                        break; \
                    case INT: \
                        RTYPE(dest) = FLOAT; \
                        REG_FLOAT(dest) = REG_FLOAT(left) op REG_INT(right); \
                        break; \
                    case FLOAT: \
                        RTYPE(dest) = FLOAT; \
                        REG_FLOAT(dest) = REG_FLOAT(left) op REG_FLOAT(right); \
                        break; \
                    case USRTYPE: \
                        runtimeWarning("defer operation for %s %s %s\n", RTTS(left), #op, RTTS(right)); \
                        break; \
                    case ADDRESS: \
                    case ERROR: \
                    case NOTHING: \
                    case BOOL: \
                        runtimeError("operation on %s %s %s is invalid\n", RTTS(left), #op, RTTS(right)); \
                        break; \
                    default: \
                        fatalError("invalid right hand type: 0x%02X", RTYPE(right)); \
                        break; \
                } \
            } \
            break; \
        case ADDRESS: { \
                switch(RTYPE(right)) { \
                    case UINT: \
                        RTYPE(dest) = ADDRESS; \
                        REG_ADDR(dest) = REG_ADDR(left) op REG_UINT(right); \
                        break; \
                    case INT: \
                        RTYPE(dest) = ADDRESS; \
                        REG_ADDR(dest) = REG_ADDR(left) op REG_INT(right); \
                        break; \
                    case ADDRESS: \
                        RTYPE(dest) = ADDRESS; \
                        REG_ADDR(dest) = REG_ADDR(left) op REG_ADDR(right); \
                        break; \
                    case USRTYPE: \
                        runtimeWarning("defer operation for %s %s %s\n", RTTS(left), #op, RTTS(right)); \
                        break; \
                    case FLOAT: \
                    case ERROR: \
                    case NOTHING: \
                    case BOOL: \
                        runtimeError("operation on %s %s %s is invalid\n", RTTS(left), #op, RTTS(right)); \
                        break; \
                    default: \
                        fatalError("invalid right hand type: 0x%02X", RTYPE(right)); \
                        break; \
                } \
            } \
            break; \
        case USRTYPE: \
            runtimeWarning("defer operation for %s %s %s\n", RTTS(left), #op, RTTS(right)); \
            break; \
        case ERROR: \
        case NOTHING: \
        case BOOL: \
            runtimeError("operation on %s %s %s is invalid\n", RTTS(left), #op, RTTS(right)); \
            break; \
        default: \
            fatalError("invalid right hand type: 0x%02X", RTYPE(right)); \
            break; \
    } \
} while(0)

void doNeg(uint8_t regs)
{
    int dest = (regs >> 4) & 0x0F,
        src = regs & 0x0F;

    switch(RTYPE(src)) {
        case UINT:
            RTYPE(dest) = INT;
            REG_INT(dest) = - REG_UINT(src);
            break;
        case INT:
            RTYPE(dest) = INT;
            REG_INT(dest) = - REG_INT(src);
            break;
        case FLOAT:
            RTYPE(dest) = FLOAT;
            REG_FLOAT(dest) = - REG_FLOAT(src);
            break;
        case BOOL:
            RTYPE(dest) = BOOL;
            REG_BOOL(dest) = REG_BOOL(src)? false: true;
            break;
        case USRTYPE:
        case ERROR:
        case NOTHING:
        case ADDRESS:
            break;
        default:
            break;
    }
}

void doAdd(uint16_t regs)
{
    int dest = (regs >> 8) & 0x0F,
        left = (regs >> 4) & 0x0F,
        right = regs & 0x0f;

    _operation(+, dest, left, right);
}

void doSub(uint16_t regs)
{
    int dest = (regs >> 8) & 0x0F,
        left = (regs >> 4) & 0x0F,
        right = regs & 0x0f;

    _operation(-, dest, left, right);
}

void doMul(uint16_t regs)
{
    int dest = (regs >> 8) & 0x0F,
        left = (regs >> 4) & 0x0F,
        right = regs & 0x0f;

    _operation(*, dest, left, right);
}

void doDiv(uint16_t regs)
{
    int dest = (regs >> 8) & 0x0F,
        left = (regs >> 4) & 0x0F,
        right = regs & 0x0f;

    _verify(right);
    _operation(/, dest, left, right);
}

void doMod(uint16_t regs)
{
    int dest = (regs >> 8) & 0x0F,
        left = (regs >> 4) & 0x0F,
        right = regs & 0x0f;

    _verify(right);

    switch(RTYPE(left)) {
        case UINT: {
                switch(RTYPE(right)) {
                    case UINT:
                        RTYPE(dest) = UINT;
                        REG_UINT(dest) = REG_UINT(left) % REG_UINT(right);
                        break;
                    case INT:
                        RTYPE(dest) = INT;
                        REG_INT(dest) = REG_UINT(left) % REG_INT(right);
                        break;
                    case FLOAT:
                        RTYPE(dest) = FLOAT;
                        REG_FLOAT(dest) = fmodf((float)REG_UINT(left), REG_FLOAT(right));
                        break;
                    case ADDRESS:
                        RTYPE(dest) = ADDRESS;
                        REG_ADDR(dest) = REG_UINT(left) % REG_ADDR(right);
                        break;
                    case USRTYPE:
                        runtimeWarning("defer operation for %s %% %s\n", RTTS(left), RTTS(right));
                        break;
                    case ERROR:
                    case NOTHING:
                    case BOOL:
                        runtimeError("operation on %s %% %s is invalid\n", RTTS(left), RTTS(right));
                        break;
                    default:
                        fatalError("invalid right hand type: 0x%02X", RTYPE(right));
                        break;
                }
            }
            break;
        case INT: {
                switch(RTYPE(right)) {
                    case UINT:
                        RTYPE(dest) = INT;
                        REG_INT(dest) = REG_INT(left) % REG_UINT(right);
                        break;
                    case INT:
                        RTYPE(dest) = INT;
                        REG_INT(dest) = REG_INT(left) % REG_INT(right);
                        break;
                    case FLOAT:
                        RTYPE(dest) = FLOAT;
                        REG_FLOAT(dest) = fmodf((float)REG_INT(left), REG_FLOAT(right));
                        break;
                    case ADDRESS:
                        RTYPE(dest) = ADDRESS;
                        REG_ADDR(dest) = REG_INT(left) % REG_ADDR(right);
                        break;
                    case USRTYPE:
                        runtimeWarning("defer operation for %s %% %s\n", RTTS(left), RTTS(right));
                        break;
                    case ERROR:
                    case NOTHING:
                    case BOOL:
                        runtimeError("operation on %s %% %s is invalid\n", RTTS(left), RTTS(right));
                        break;
                    default:
                        fatalError("invalid right hand type: 0x%02X", RTYPE(right));
                        break;
                }
            }
            break;
        case FLOAT: {
                switch(RTYPE(right)) {
                    case UINT:
                        RTYPE(dest) = FLOAT;
                        REG_FLOAT(dest) = fmodf((float)REG_FLOAT(left), REG_UINT(right));
                        break;
                    case INT:
                        RTYPE(dest) = FLOAT;
                        REG_FLOAT(dest) = fmodf((float)REG_FLOAT(left), REG_INT(right));
                        break;
                    case FLOAT:
                        RTYPE(dest) = FLOAT;
                        REG_FLOAT(dest) = fmodf((float)REG_FLOAT(left), REG_FLOAT(right));
                        break;
                    case USRTYPE:
                        runtimeWarning("defer operation for %s %% %s\n", RTTS(left), RTTS(right));
                        break;
                    case ADDRESS:
                    case ERROR:
                    case NOTHING:
                    case BOOL:
                        runtimeError("operation on %s %% %s is invalid\n", RTTS(left), RTTS(right));
                        break;
                    default:
                        fatalError("invalid right hand type: 0x%02X", RTYPE(right));
                        break;
                }
            }
            break;
        case ADDRESS: {
                switch(RTYPE(right)) {
                    case UINT:
                        RTYPE(dest) = ADDRESS;
                        REG_ADDR(dest) = REG_ADDR(left) % REG_UINT(right);
                        break;
                    case INT:
                        RTYPE(dest) = ADDRESS;
                        REG_ADDR(dest) = REG_ADDR(left) % REG_INT(right);
                        break;
                    case ADDRESS:
                        RTYPE(dest) = ADDRESS;
                        REG_ADDR(dest) = REG_ADDR(left) % REG_ADDR(right);
                        break;
                    case USRTYPE:
                        runtimeWarning("defer operation for %s %% %s\n", RTTS(left), RTTS(right));
                        break;
                    case FLOAT:
                    case ERROR:
                    case NOTHING:
                    case BOOL:
                        runtimeError("operation on %s %% %s is invalid\n", RTTS(left), RTTS(right));
                        break;
                    default:
                        fatalError("invalid right hand type: 0x%02X", RTYPE(right));
                        break;
                }
            }
            break;
        case USRTYPE:
            runtimeWarning("defer operation for %s %% %s\n", RTTS(left), RTTS(right));
            break;
        case ERROR:
        case NOTHING:
        case BOOL:
            runtimeError("operation on %s %% %s is invalid\n", RTTS(left), RTTS(right));
            break;
        default:
            fatalError("invalid right hand type: 0x%02X", RTYPE(right));
            break;
    }
}
