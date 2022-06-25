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
// #include "vMachine.h"
// #include "traps.h"
// #include "print.h"
// #include "strutils.h"

#include "gvm.h"

/**
 * @brief The value to print is in R0. There is no return value.
 *
 * @param vm
 *
 */
static void print_trap()
{
    printReg(getReg(0), stdout);
}

static void format_str_trap()
{
    // get the string to manipulate
    Value* val = getReg(0);
    if(val->type != STRING) {
        fprintf(stderr, "trap error: R0 does not contain a string");
        exit(1);
    }
    const char* src = getStr(val->data.str);

    // do the manipulation
    const char* dest = format_str(src);

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

    // save it in R0
}

void doTrap(TrapNumType tno)
{
    switch(tno) {
        case PRINT:     print_trap(); break;
        case FMT_STR:   format_str_trap(); break;
        case GET_TIME:  get_time_trap(); break;
        default:
            fprintf(stderr, "fatal error: unknown trap number encountered: %d", tno);
            exit(1);
    }
    printf("\n");
}