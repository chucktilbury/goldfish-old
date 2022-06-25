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
#include "vMachine.h"
#include "traps.h"
#include "print.h"
#include "strutils.h"

/**
 * @brief The value to print is in R0. There is no return value.
 *
 * @param vm
 *
 */
static void print_trap(VM* vm)
{
    printReg(vm, &vm->registers[0], stdout);
}

static void format_str_trap(VM* vm)
{
    // get the string to manipulate
    Value val = vm->registers[0];
    if(val.type != STRING) {
        fprintf(stderr, "trap error: R0 does not contain a string");
        exit(1);
    }
    const char* src = getStr(&vm->sstore, val.data.str);

    // do the manipulation
    String* dest = format_str(vm, src);

    // store the result in R0
    val.type = STRING;
    val.data.str = 0; //dest;
    val.isConst = true;
    val.isAssigned = true;
    vm->registers[0] = val;
}

static void get_time_trap(VM* vm)
{
    // read the time from the system

    // save it in R0
}

void doTrap(VM* vm, TrapNumType tno)
{
    switch(tno) {
        case PRINT:     print_trap(vm); break;
        case FMT_STR:   format_str_trap(vm); break;
        case GET_TIME:  get_time_trap(vm); break;
        default:
            fprintf(stderr, "fatal error: unknown trap number encountered: %d", tno);
            exit(1);
    }
    printf("\n");
}