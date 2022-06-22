
#include "vMachine.h"
#include "print.h"

/**
 * @brief Print a raw value.
 *
 * @param val
 * @param outf
 *
 */
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
        case STRING: fprintf(outf, "<defer>"); break;
        default: fprintf(outf, "UNKNOWN"); break;
    }
    //fprintf(outf, "\n");
}

/**
 * @brief Print a string object
 *
 * @param store
 * @param idx
 * @param outf
 *
 */
void printStr(StrStore* store, Index idx, FILE* outf)
{
    fprintf(outf, "<%s>", getStr(store, idx));
}

/**
 * @brief Print an object given the store pointer and index.
 *
 * @param store
 * @param idx
 * @param fp
 *
 */
void printVar(VarStore* store, Index idx, FILE* fp)
{
    printVal(getVar(store, idx), fp);
}

/**
 * @brief Print an object given the vm pointer and the index. The index is a
 * VarStore index, but this function can trace compound and user objects to
 * a print method.
 *
 * @param vm
 * @param idx
 * @param fp
 *
 */
void printObj(VM* vm, Index idx, FILE* fp)
{
    Value* val = getVar(&vm->vstore, idx);

    switch(val->type) {
        case ERROR:
        case NOTHING:
        case UINT:
        case INT:
        case FLOAT:
        case BOOL:
        case ADDRESS:
            printVal(val, fp);
            break;

        case STRING:
            fprintf(fp, "%-8s", valTypeToStr(val->type));
            printStr(&vm->sstore, val->data.str, fp);
            break;

        case USRTYPE:
            // user type figures out what to print and how
            fprintf(fp, "%-8s", valTypeToStr(val->type));
            fprintf(fp, "<defer>");
            break;

        default:
            fprintf(fp, "UNKNOWN");
            break;
    }

}

/**
 * @brief Print the register given the value and the vm.
 *
 * @param vm
 * @param val
 * @param fp
 *
 */
void printReg(VM* vm, Value* val, FILE* fp)
{
    switch(val->type) {
        case ERROR:
        case NOTHING:
        case UINT:
        case INT:
        case FLOAT:
        case BOOL:
        case ADDRESS:
            printVal(val, fp);
            break;

        case STRING:
            //fprintf(stderr, "string index: %d\n", val->data.str);
            fprintf(fp, "%-8s", valTypeToStr(val->type));
            printStr(&vm->sstore, val->data.str, fp);
            break;

        case USRTYPE:
            // user type figures out what to print and how
            fprintf(fp, "%-8s", valTypeToStr(val->type));
            fprintf(fp, "<defer>");
            break;

        default:
            fprintf(fp, "UNKNOWN");
            break;
    }
}
