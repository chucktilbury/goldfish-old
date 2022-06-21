
#include "system.h"
#include "varStore.h"
#include "vMachine.h"
#include "errors.h"
#include "memory.h"

extern VM* vm;
#include "symtab.h"

typedef struct _symtab_elem {
    const char* key;
    VarIdx idx;
    struct _symtab_elem* left;
    struct _symtab_elem* right;
} SymTabNode;

static SymTabNode* symtab = NULL;

// left is always the value that is being searched for
static int comp_names(const char* left, const char* right)
{
    return strcmp(left, right);
}

static void dump_table(SymTabNode* node)
{
    if(node->left != NULL)
        dump_table(node->left);
    if(node->right != NULL)
        dump_table(node->right);

    printf("    %-12s\t<%d>\t", node->key, node->idx);
    printVal(getVar(&vm->vstore, node->idx));
    //printf("\n");
}

static void add_node(SymTabNode* tree, SymTabNode* node)
{
    int x = comp_names(tree->key, node->key);
    if(x > 0) {
        if(tree->right != NULL)
            add_node(tree->right, node);
        else {
            tree->right = node;
            return;
        }
    }
    else if(x < 0) {
        if(tree->left != NULL)
            add_node(tree->left, node);
        else {
            tree->left = node;
            return;
        }
    }
    else {
        syntaxError("symbol \"%s\" is already defined", node->key);
        return;
    }
}

static SymTabNode* find_node(SymTabNode* node, const char* key)
{
    int x = comp_names(node->key, key);
    if(x > 0) {
        if(node->right != NULL)
            return find_node(node->right, key);
        else
            return NULL;
    }
    else if(x < 0) {
        if(node->left != NULL)
            return find_node(node->left, key);
        else
            return NULL;
    }
    else
        return node;
}

/*************************************************************
 * Interface
 */

// symbol definition
void addSym(const char* key, VarIdx idx)
{
    //printf("addSym(%s, %d)\n", key, idx);
    SymTabNode* node = _alloc_ds(SymTabNode);
    node->key = _copy_str(key);
    node->idx = idx;

    if(symtab != NULL)
        add_node(symtab, node);
    else
        symtab = node;
}

// symbol reference
VarIdx symToIdx(const char* key)
{
    SymTabNode* node = find_node(symtab, key);

    if(node != NULL)
        return node->idx;
    else
        return 0;   // error Var
}

// symbol reference
Value* symToVal(const char*key)
{
    SymTabNode* node = find_node(symtab, key);
    Value* val;

    if(node != NULL)
        val = getVar(&vm->vstore, node->idx);
    else {
        memset(val, 0, sizeof(Value));
        val->type = ERROR;
    }

    return val;
}

bool symIsDefined(const char* key)
{
    return (find_node(symtab, key))? true: false;
}

void dumpSymtab()
{
    printf("Dump Symbol Table\n");
    if(symtab != NULL)
        dump_table(symtab);
    else
        printf("    table is empty\n");
    printf("----------- end dump -----------\n");
}

