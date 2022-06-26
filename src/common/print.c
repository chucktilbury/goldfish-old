
// #include "vMachine.h"
// #include "print.h"

#include "common.h"

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
    fprintf(outf, "<%s>", valToStr(val)->list);
}

/**
 * @brief Print a string object
 *
 * @param idx
 * @param outf
 *
 */
void printStr(Index idx, FILE* outf)
{
    fprintf(outf, "<%s>", getStr(idx));
}

/**
 * @brief Print an object given the store pointer and index.
 *
 * @param idx
 * @param fp
 *
 */
void printVar(Index idx, FILE* fp)
{
    printVal(getVar(idx), fp);
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
void printObj(Index idx, FILE* fp)
{
    Value* val = getVar(idx);
    fprintf(fp, "%-8s<%s>", valTypeToStr(val->type), valToStr(val)->list);
    fprintf(fp, "%s", valToStr(val)->list);
}

/**
 * @brief Print the register given the value and the vm.
 *
 * @param vm
 * @param val
 * @param fp
 *
 */
void printReg(Value* val, FILE* fp)
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
            //fprintf(fp, "%-8s", valTypeToStr(val->type));
            printStr(val->data.str, fp);
            break;

        case USRTYPE:
            // user type figures out what to print and how
            //fprintf(fp, "%-8s", valTypeToStr(val->type));
            fprintf(fp, "<defer>");
            break;

        default:
            fprintf(fp, "UNKNOWN");
            break;
    }
}
