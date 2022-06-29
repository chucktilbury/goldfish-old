
// #include "system.h"
// #include "varStore.h"
// #include "vMachine.h"
// #include "errors.h"
// #include "memory.h"
// #include "print.h"

#include "gas.h"

typedef struct _symtab_elem {
    const char* key;
    Index idx;
    struct _symtab_elem* left;
    struct _symtab_elem* right;
} SymTabNode;

static SymTabNode* symtab = NULL;

// left is always the value that is being searched for
static int comp_names(const char* left, const char* right)
{
    return strcmp(left, right);
}

static void dump_table(SymTabNode* node, FILE* outf)
{
    //fprintf(stderr, "dump node: %p\n", node);
    if(node->left != NULL)
        dump_table(node->left, outf);
    if(node->right != NULL)
        dump_table(node->right, outf);

    fprintf(outf, "    %-12s\t<%d>\t", node->key, node->idx);
    printVal(getVar(node->idx), outf);
    printf("\n");
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
void addSym(const char* key, Index idx)
{
    fprintf(stderr, "addSym(%s, %d)\n", key, idx);
    SymTabNode* node = _alloc_ds(SymTabNode);
    node->left = NULL;
    node->right = NULL;
    node->key = _copy_str(key);
    node->idx = idx;

    //fprintf(stderr, "add node: %p\n", node);
    if(symtab != NULL)
        add_node(symtab, node);
    else
        symtab = node;
}

// symbol reference
Index symToIdx(const char* key)
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
        val = getVar(node->idx);
    else
        val = getVar(0);

    return val;
}

bool symIsDefined(const char* key)
{
    return (find_node(symtab, key))? true: false;
}

void dumpSymtab(FILE* outf)
{
    fprintf(outf, "-------- Dump Symbol Table ----------\n");
    if(symtab != NULL)
        dump_table(symtab, outf);
    else
        fprintf(outf, "    table is empty\n");
    fprintf(outf, "----------- end dump -----------\n\n");
}
