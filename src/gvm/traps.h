#ifndef TRAPS_H
#define TRAPS_H

#include "vm.h"

typedef uint16_t TrapNumType;
// typedef enum {
//     PRINT,
//     DBG_PRINT,
//     FMT_STR,
//     GET_TIME,
//     STR_TIME,
// } TrapNumber;

#include "../runtime/traps.inc"

void doTrap(TrapNumType tno);

#endif
