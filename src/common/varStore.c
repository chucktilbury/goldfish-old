
#include "varStore.h"
#include "memory.h"

static VarIdx find_slot(VarStore* store)
{
    if(store->free_slots > 0) {
        for(VarIdx idx = 0; idx < store->len; idx++) {
            if(store->list[idx].status == DELETED) {
                store->free_slots--;
                store->list[idx].status = ACTIVE;
                return idx;
            }
        }
        return 0; // error
    }

    if(store->cap < store->len-1)
        store->cap <<= 1;
    store->list = _realloc_ds_array(store->list, Variable, store->cap);

    VarIdx idx = store->len;
    store->len++;

    return idx;
}

static bool validateIdx(VarStore* store, VarIdx idx)
{
    if(idx < store->len) {
        if(store->list[idx].status != DELETED)
            return true;
    }

    return false;
}

void initVarStore(VarStore* store)
{
    store->cap = 0x01 << 3;
    store->list = _alloc_ds_array(Variable, store->cap);

    // set up the error variable
    store->len = 1;
    Variable* var = &store->list[0];
    var->status = ACTIVE;
    var->val.isAssigned = true;
    var->val.type = ERROR;
}

VarIdx createVar(VarStore* store, ValType type)
{
    Value val;
    VarIdx idx = find_slot(store);
    val.type = type;
    store->list[idx].val = val;
    store->list[idx].val.isAssigned = false;
    store->list[idx].status = ACTIVE;

    return idx;
}

VarIdx assignVar(VarStore* store, VarIdx idx, Value val)
{
    if(!validateIdx(store, idx))
        return 0;
    else {
        store->list[idx].val = val;
        store->list[idx].val.isAssigned = true;
    }

    return idx;
}

VarIdx assignVarName(VarStore* store, VarIdx vidx, StrIdx sidx)
{
    if(!validateIdx(store, vidx))
        return 0;
    else
        store->list[vidx].name = sidx;

    return vidx;
}

VarIdx addVar(VarStore* store, Value val)
{
    VarIdx idx = find_slot(store);
    //printf("add var slot: %d\n", idx);
    store->list[idx].val = val;
    //store->list[idx].val.isAssigned = true;
    store->list[idx].status = ACTIVE;

    return idx;
}

Value* getVar(VarStore* store, VarIdx idx)
{
    if(validateIdx(store, idx))
        return &store->list[idx].val;
    else
        return &store->list[0].val;
}

void delVar(VarStore* store, VarIdx idx)
{
    if(validateIdx(store, idx)) {
        store->list[idx].status = DELETED;
        store->free_slots ++;
    }
}

void dumpVars(VarStore* store, FILE* outf)
{
    fprintf(outf, "-------- Dump Variable Table ----------\n");

    for(uint32_t i = 0; i < store->len; i++) {
        fprintf(outf, "<%d>\t", i);
        printVal(&store->list[i].val, outf);
        fprintf(outf, "\tstatus: %s\t", store->list[i].status? "DELETED": "ACTIVE");
        fprintf(outf, "<%d>\n", store->list[i].name);
    }
    fprintf(outf, "-------- end dump ----------\n\n");
}
