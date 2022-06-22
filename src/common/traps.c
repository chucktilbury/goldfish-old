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

static void print_trap(VM* vm)
{
    printReg(vm, &vm->registers[0], stdout);
}

void doTrap(VM* vm, TrapNumType tno)
{
    switch(tno) {
        case PRINT:
            print_trap(vm);
            break;
        default:
            fprintf(stderr, "fatal error: unknown trap number encountered: %d", tno);
            exit(1);
    }
    printf("\n");
}