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

    switch(type) {
        case NOTHING:
            retv.type = type;
            switch(val.type) {
                case NOTHING: break;
                case UINT:
                case INT:
                case FLOAT:
                case BOOL:
                case ADDRESS:
                case USRTYPE:
                case ERROR:
                    error("cannot cast a %s type to a %s", valTypeToStr(val.type), type);
                    retv.type = ERROR;
                    break;
                default:
                    fatal("unknown value type in cast: 0x%02X", val.type);
            }
            break;
        case UINT:
            retv.type = type;
            switch(val.type) {
                case NOTHING:
                case UINT: retv.data.unum = val.data.unum; break;
                case INT: retv.data.unum = (uint64_t)val.data.inum; break;
                case FLOAT: retv.data.unum = (uint64_t)val.data.fnum; break;
                case BOOL: retv.data.unum = val.data.boolean; break;
                case ADDRESS: retv.data.unum = val.data.addr; break;
                case USRTYPE:
                case ERROR:
                    error("cannot cast a %s type to a %s", valTypeToStr(val.type), type);
                    retv.type = ERROR;
                    break;
                default:
                    fatal("unknown value type in cast: 0x%02X", val.type);
            }
            break;
        case INT:
            retv.type = type;
            switch(val.type) {
                case NOTHING:
                case UINT: retv.data.inum = (int64_t)val.data.unum; break;
                case INT: retv.data.inum = val.data.inum; break;
                case FLOAT: retv.data.inum = (int64_t)val.data.fnum; break;
                case BOOL: retv.data.inum = val.data.boolean; break;
                case ADDRESS: retv.data.inum = (int64_t)val.data.addr; break;
                case USRTYPE:
                case ERROR:
                    error("cannot cast a %s type to a %s", valTypeToStr(val.type), type);
                    retv.type = ERROR;
                    break;
                default:
                    fatal("unknown value type in cast: 0x%02X", val.type);
            }
            break;
        case FLOAT:
            retv.type = type;
            switch(val.type) {
                case NOTHING:
                case UINT: retv.data.fnum = (double)((int64_t)val.data.unum); break;
                case INT: retv.data.fnum = (double)val.data.inum; break;
                case FLOAT: retv.data.fnum = val.data.fnum; break;
                case BOOL: retv.data.fnum = (double)val.data.boolean? 1.0: 0.0; break;
                case ADDRESS: retv.data.fnum = (double)val.data.addr; break;
                case USRTYPE:
                case ERROR:
                    error("cannot cast a %s type to a %s", valTypeToStr(val.type), type);
                    retv.type = ERROR;
                    break;
                default:
                    fatal("unknown value type in cast: 0x%02X", val.type);
            }
            break;
        case BOOL:
            retv.type = type;
            switch(val.type) {
                case NOTHING:
                case UINT: retv.data.boolean = val.data.unum == 0? false: true; break;
                case INT: retv.data.boolean = val.data.inum == 0? false: true; break;
                case FLOAT: retv.data.boolean = val.data.fnum != 0.0? true: false; break;
                case BOOL: retv.data.boolean = val.data.boolean; break;
                case ADDRESS: retv.data.boolean = val.data.addr == 0? false: true; break;
                case USRTYPE:
                case ERROR:
                    error("cannot cast a %s type to a %s", valTypeToStr(val.type), type);
                    retv.type = ERROR;
                    break;
                default:
                    fatal("unknown value type in cast: 0x%02X", val.type);
            }
            break;
        case ADDRESS:
            retv.type = type;
            switch(val.type) {
                case NOTHING:
                case UINT: retv.data.addr = val.data.unum; break;
                case INT: retv.data.addr = (uint64_t)val.data.inum; break;
                case ADDRESS: retv.data.addr = val.data.addr; break;
                case FLOAT:
                case BOOL:
                case USRTYPE:
                case ERROR:
                    error("cannot cast a %s type to a %s", valTypeToStr(val.type), type);
                    retv.type = ERROR;
                    break;
                default:
                    fatal("unknown value type in cast: 0x%02X", val.type);
            }
            break;
        case USRTYPE:
        case ERROR:
            error("cannot case a %s type to a %s", valTypeToStr(val.type), type);
            retv.type = ERROR;
            break;
        default:
            fatal("unknown value type in cast: 0x%02X", val.type);
    }


    return retv;
}

void copyValue(Value* dest, Value* src)
{
    memcpy(dest, src, sizeof(Value));
}

void printVal(Value* val, FILE* outf)
{
    fprintf(outf, "%-8s", valTypeToStr(val->type));
    switch(val->type) {
        case ERROR: fprintf(outf, "<ERROR>"); break;
        case NOTHING: fprintf(outf, "<NOTHING>"); break;
        case UINT: fprintf(outf, "<0x%02lX>", val->data.unum); break;
        case INT: fprintf(outf, "<%ld>", val->data.inum); break;
        case FLOAT: fprintf(outf, "<%0.3f>", val->data.fnum); break;
        case BOOL: fprintf(outf, "<%s>", val->data.boolean? "true": "false"); break;
        case ADDRESS: fprintf(outf, "<%d>", val->data.addr); break;
        case USRTYPE: fprintf(outf, "<defer>"); break;
        default: fprintf(outf, "UNKNOWN"); break;
    }
    //fprintf(outf, "\n");
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
            (type == USRTYPE)? "USRTYPE":"UNKNOWN";
}

