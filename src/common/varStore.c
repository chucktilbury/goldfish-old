
#include "common.h"

typedef struct {
    Value val;
    Status status;
    Index name;
} Variable;

typedef struct {
    Variable* list;
    uint32_t cap;
    uint32_t len;
    uint32_t free_slots;
    uint32_t index;
} VarStore;

static VarStore store;

static Index find_slot()
{
    if(store.free_slots > 0) {
        for(Index idx = 0; idx < store.len; idx++) {
            if(store.list[idx].status == DELETED) {
                store.free_slots--;
                store.list[idx].status = ACTIVE;
                return idx;
            }
        }
        return 0; // error
    }

    if(store.cap < store.len-1) {
        store.cap <<= 1;
        store.list = _realloc_ds_array(store.list, Variable, store.cap);
    }

    Index idx = store.len;
    store.len++;

    return idx;
}

static bool validateIdx(Index idx)
{
    //fprintf(stderr, "validating index: %d: ", idx);
    if(idx < store.len) {
        if(store.list[idx].status != DELETED) {
            //fprintf(stderr, "index is VALID\n");
            return true;
        }
    }

    //fprintf(stderr, "index is NOT VALID\n");
    return false;
}

void initVarStore()
{
    store.cap = 0x01 << 3;
    store.list = _alloc_ds_array(Variable, store.cap);
    store.index = 0;

    // set up the error variable
    store.len = 1;
    Variable* var = &store.list[0];
    var->status = ACTIVE;
    var->val.isAssigned = true;
    var->val.type = ERROR;
}

void loadVarStore(FILE* fp)
{
    fread(&store.len, sizeof(store.len), 1, fp);

    store.cap = 1;
    while(store.cap <= store.len)
        store.cap <<= 1;

    store.list = _alloc_ds_array(Variable, store.len);
    fread(store.list, sizeof(Variable), store.len, fp);
}

void saveVarStore(FILE* fp)
{
    fwrite(&store.len, sizeof(store.len), 1, fp);
    fwrite(store.list, sizeof(Variable), store.len, fp);
}

Index createVar(ValType type)
{
    Value val;
    Index idx = find_slot(store);
    val.type = type;
    store.list[idx].val = val;
    store.list[idx].val.isAssigned = false;
    store.list[idx].status = ACTIVE;

    return idx;
}

Index assignVar(Index idx, Value* val)
{
    fprintf(stderr, "assign var: type:%s idx:%d\n", valTypeToStr(val->type), idx);
    if(!validateIdx(idx))
        return 0;
    else {
        memcpy(&store.list[idx].val, val, sizeof(Value));
        //store.list[idx].val = *val;
        //store.list[idx].val.isAssigned = true;
        store.list[idx].status = ACTIVE;
    }

    return idx;
}

Index assignVarName(Index vidx, Index sidx)
{
    if(!validateIdx(vidx))
        return 0;
    else
        store.list[vidx].name = sidx;

    return vidx;
}

Index addVar(Value val)
{
    Index idx = find_slot();
    fprintf(stderr, "add var slot: %d\n", idx);
    store.list[idx].val = val;
    //store.list[idx].val.isAssigned = true;
    store.list[idx].status = ACTIVE;

    return idx;
}

Value* getVar(Index idx)
{
    if(validateIdx(idx))
        return &store.list[idx].val;
    else
        return &store.list[0].val;
}

void delVar(Index idx)
{
    if(validateIdx(idx)) {
        store.list[idx].status = DELETED;
        store.free_slots ++;
    }
}

void dumpVars(FILE* outf)
{
    fprintf(outf, "-------- Dump Variable Table ----------\n");

    for(uint32_t i = 0; i < store.len; i++) {
        fprintf(outf, "<%d>\t", i);
        printVal(&store.list[i].val, outf);
        fprintf(outf, "\tstatus: %s\t", !store.list[i].status? "DELETED": "ACTIVE");
        fprintf(outf, "<%d>\n", store.list[i].name);
    }
    fprintf(outf, "-------- end dump ----------\n\n");
}

Value* resetVars()
{
    store.index = 0;
    return &store.list[store.index++].val;
}

Value* iterateVars()
{
    if(store.index > store.len)
        return NULL;

    while(store.list[store.index].status == DELETED) {
        store.index++;
        if(store.index > store.len)
            return NULL;
    }
    //fprintf(stderr, "index:: %d\n", store.index);
    return &store.list[store.index++].val;
}

Index getVarName()
{
    return store.list[store.index-1].name;
}

