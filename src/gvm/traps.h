#ifndef TRAPS_H
#define TRAPS_H

#include "vMachine.h"

typedef uint16_t TrapNumType;
typedef enum {
    PRINT,
    FMT_STR,
    GET_TIME,
} TrapNumber;

void doTrap(VM* vm, TrapNumType tno);

#endif