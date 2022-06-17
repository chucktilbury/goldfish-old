#ifndef VALUES_H
#define VALUES_H

#include "system.h"

typedef enum {
    ERROR,      // union data is undefined
    NOTHING,    // union data is undefined
    UINT,
    INT,
    FLOAT,
    BOOL,
    ADDRESS,
    ARRAY,
    USRTYPE,
    DEFER, // used in the tables to mark deferred transformations
    EXTERN, // external function defined in external code
} ValType;

// use shallow copy, rather than heap allocation
typedef struct {
    ValType type;
    bool isConst;
    union {
        uint64_t unum;
        int64_t inum;
        double fnum;
        bool boolean;
        uint32_t addr;
        // these are indexes into their respective stores...
        int array;
        int usrtype;
    } data;
} __attribute__((packed)) Value;


Value castValue(ValType type, Value val, bool isConst);
// Convert the type to a string for debugging and error generation.
const char* valTypeToStr(ValType type);
void printVal(Value val);

#endif

