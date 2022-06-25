
// #include "doJmps.h"
// #include "vmErrors.h"

#include "gvm.h"

/**
 * @brief A call has stack elements expected. The address is delivered in
 * various ways, given by the instruction type, but in addition to that, the
 * function parameters are required to execute a call. The TOS will be the
 * number of function args that are on the stack. That number is then used to
 * allocate the array of elements, which is then popped and store in the
 * array. When the code that has been called is entered, the stack is neutral
 * with no data that is relevant to the call.
 *
 * @param vm
 * @param val
 */
void doCall(Value* val)
{
    int idx;
    switch(val->type) {
        case ADDRESS:   idx = (int)val->data.addr;   break;

        case UINT:
        case INT:
        case ERROR:
        case NOTHING:
        case FLOAT:
        case BOOL:
        case USRTYPE:
            runtimeError("invalid call address type: %s", valTypeToStr(val->type));
            break;
        default:
            fatalError("invalid address type encountered: 0x%02X", val->type);
    }

    Value ret;
    ret.type = ADDRESS;
    ret.data.addr = getInstrIndex();
    ret.isAssigned = true;

    pushValStack(&ret);
    setInstrIndex(idx);
}

void doJmp(Value* val)
{
    int idx;

    switch(val->type) {
        case ADDRESS:   idx = (int)val->data.addr;   break;

        case UINT:
        case INT:
        case ERROR:
        case NOTHING:
        case FLOAT:
        case BOOL:
        case USRTYPE:
            runtimeError("cannot use type %s as a jmp address", valTypeToStr(val->type));
            break;
        default:
            fatalError("invalid address type encountered: 0x%02X", val->type);
    }

    setInstrIndex(idx);
}

void doBr(Value* val)
{
    if(getFlag()) {
        int idx;

        switch(val->type) {
            case ADDRESS:   idx = (int)val->data.addr;   break;

            case UINT:
            case INT:
            case ERROR:
            case NOTHING:
            case FLOAT:
            case BOOL:
            case USRTYPE:
                runtimeError("cannot use type %s as a jmp address", valTypeToStr(val->type));
                break;
            default:
                fatalError("invalid address type encountered: 0x%02X", val->type);
        }

        setInstrIndex(idx);
    }
}

void doReturn()
{
    Value* val = popValStack();

    int idx;
    switch(val->type) {
        case ADDRESS:   idx = (int)val->data.addr;   break;

        case UINT:
        case INT:
        case ERROR:
        case NOTHING:
        case FLOAT:
        case BOOL:
        case USRTYPE:
            runtimeError("invalid return address type: %s", valTypeToStr(val->type));
            break;
        default:
            fatalError("invalid address type encountered: 0x%02X", val->type);
    }

    setInstrIndex(idx);
}

