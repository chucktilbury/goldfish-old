/**
 * @file values.c
 * @brief Implement values and all of the operations required for them.
 */
#include "values.h"
#include "errors.h"

Value castValue(ValType type, Value val, bool isConst)
{
    Value retv;
    retv.isConst = isConst;

    switch(val.type) {
        case NOTHING:
        case UINT:
        case INT:
        case FLOAT:
        case BOOL:
        case ADDRESS:
        case ARRAY:
        case USRTYPE:
        case ERROR:
            error("cannot case a %s type to a %s", varTypeToStr(val.type), type);
            retv.type = ERROR;
            break;
        default:
            fatal("unknown value type in cast: 0x%02X", val.type);
    }


    return retv;
}

void printVal(Value val)
{
    printf("%s: ", valTypeToStr(val.type));
    switch(val.type) {
        case ERROR: printf("<ERROR>"); break;
        case NOTHING: printf("<NOTHING>"); break;
        case UINT: printf("<0x%02lX>", val.data.unum); break;
        case INT: printf("<%ld>", val.data.inum); break;
        case FLOAT: printf("<%0.3f>", val.data.fnum); break;
        case BOOL: printf("<%s>", val.data.boolean? "true": "false"); break;
        case ADDRESS: printf("<0x%08X>", val.data.addr); break;
        case ARRAY: printf("<defer>"); break;
        case USRTYPE: printf("<defer>"); break;
        default: printf("UNKNOWN"); break;
    }
    printf("\n");
}

const char* valTypeToStr(ValType type)
{
    return (type == ERROR)? "ERROR":
            (type == NOTHING)? "NOTHING":
            (type == UINT)? "UINT":
            (type == INT)? "INT":
            (type == FLOAT)? "FLOAT":
            (type == BOOL)? "BOOL":
            (type == ADDRESS)? "ADDRESS":
            (type == ARRAY)? "ARRAY":
            (type == USRTYPE)? "USRTYPE":"UNKNOWN";
}

