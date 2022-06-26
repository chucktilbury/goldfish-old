/**
 * @file traps.c
 * @brief Traps are the interface into the outside world. When a trap is
 * executed, there is a trap number that corresponds to the actual function
 * that will be entered when the trap is executed. The parameters of the
 * function can be set up any way that the developer wants, and there are no
 * restrictions on what can be accessed by a trap function. That having been
 * said, there is little error checking on trap calls. If the person writing
 * the assembly does it wrong, bad things are guaranteed to happen. Therefore,
 * traps should be used carefully and mindful of the documentation.
 *
 */

#include "gvm.h"
#include <time.h>
/**
 * @brief The value to print is in R0. There is no return value.
 *
 * @param vm
 *
 */
static void print_dbg_trap()
{
    //printReg(getReg(0), stdout);
    Value* val = getReg(0);
    fprintf(stdout, "%-8s<%s>\n", valTypeToStr(val->type), valToStr(val)->list);
}

static void print_trap()
{
    //printReg(getReg(0), stdout);
    Value* val = getReg(0);
    fprintf(stdout, "%s\n", valToStr(val)->list);
}

static void format_str_trap()
{
    // get the string to manipulate
    Value* val = getReg(0);
    if(val->type != STRING) {
        fprintf(stderr, "trap error: R0 does not contain a string\n");
        exit(1);
    }
    const char* src = getStr(val->data.str);

    // do the manipulation
    const char* dest = formatStr(src);

    Index idx = addStr(dest);

    // store the result in R0
    val->type = STRING;
    val->data.str = idx; //dest;
    val->isConst = true;
    val->isAssigned = true;
    setReg(0, val);
}

static void get_time_trap()
{
    // read the time from the system
    time_t t = time(NULL);
    Value val;
    val.type = UINT;
    val.data.unum = t;
    val.isAssigned = true;
    val.isConst = true;
    setReg(0, &val);
    // save it in R0
}

static void str_time_trap()
{
    Value* val = getReg(0);
    if(val->type != UINT && val->type != INT) {
        fprintf(stderr, "trap error: R0 does not contain an int\n");
        exit(1);
    }

    time_t t = val->data.unum;
    String* str = createStr(ctime(&t));

    stripStr(str);
    // printf("%s\n", str->list);
    val->type = STRING;
    val->data.str = addStr(str->list);
    val->isAssigned = true;
    val->isConst = true;
    setReg(0, val);
}

void doTrap(TrapNumType tno)
{
    switch(tno) {
        case PRINT:     print_trap(); break;
        case DBG_PRINT: print_dbg_trap(); break;
        case FMT_STR:   format_str_trap(); break;
        case GET_TIME:  get_time_trap(); break;
        case STR_TIME:  str_time_trap(); break;
        default:
            fprintf(stderr, "fatal error: unknown trap number encountered: %d\n", tno);
            exit(1);
    }
}
