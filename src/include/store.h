#ifndef STORES_H
#define STORES_H

#include "system.h"

typedef enum {
    DELETED,
    ACTIVE,
} Status;

typedef uint32_t Index;

#include "values.h"
#include "strStore.h"
#include "varStore.h"
#include "instrStore.h"

#endif