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
    STRING,
    USRTYPE, // user types are accessed using a trap
    DEFER, // used in the tables to mark deferred transformations
    EXTERN, // external function defined in external code
} ValType;

// use shallow copy, rather than heap allocation
typedef struct {
    ValType type;
    bool isConst;
    bool isAssigned;
    union {
        uint64_t unum;
        int64_t inum;
        double fnum;
        bool boolean;
        uint32_t addr;
        int usrtype;
        int str;
    } data;
} __attribute__((packed)) Value;


Value castValue(ValType type, Value val, bool isConst);
void copyValue(Value* dest, Value* src);
// Convert the type to a string for debugging and error generation.
const char* valTypeToStr(ValType type);
void printVal(Value* val, FILE* outf);

#define VTYPE(v) (v).type
#define VDATA(v) (v).data
#define TTS(v) valTypeToStr(VTYPE(v))
#define AS_UINT(v) VDATA(v).unum
#define AS_INT(v) VDATA(v).inum
#define AS_FLOAT(v) VDATA(v).fnum
#define AS_ADDR(v) VDATA(v).addr
#define AS_BOOL(v) VDATA(v).boolean
#define AS_USR(v) VDATA(v).usrtype

#endif

