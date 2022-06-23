
#include "system.h"
#include "varStore.h"
#include "vMachine.h"
#include "asmErrors.h"
#include "memory.h"

extern VM* vm;
#include "symbolTable.h"

typedef struct _symtab_elem {
    const char* key;
    Index idx;
    struct _symtab_elem* left;
    struct _symtab_elem* right;
} SymTabNode;

typedef struct _context {
    const char* name;
    struct _context* next;
    struct _context* prev;
} Context;

static SymTabNode* symtab = NULL;
static Context* first = NULL;
static Context* last = NULL;

static char name_buffer[1024];
static void build_name(Context* cont, const char* name)
{
    if(cont != NULL) {
        strcat(name_buffer, cont->name);
        strcat(name_buffer, ".");
        build_name(cont->next, name);
    }
    else {
        strcat(name_buffer, name);
    }
}

static const char* create_name(const char* name)
{
    memset(name_buffer, 0, sizeof(name_buffer));
    name_buffer[0] = '.';
    if(first != NULL)
		build_name(first, name);
	else
		strcat(name_buffer, name);

    return name_buffer;
}

// left is always the value that is being searched for
static int comp_names(const char* left, const char* right)
{
    int llen = strlen(left);
    int rlen = strlen(right);

    while(left[llen] == right[rlen]) {
        llen--;
        rlen--;
        if(llen == 0 || rlen == 0)
            return 0;   // match
    }

    return left[llen] - right[rlen];
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
void addSym(const char* key, Index idx)
{
    SymTabNode* node = _alloc_ds(SymTabNode);
    node->key = _copy_str(create_name(key));
    node->idx = idx;

    if(symtab != NULL)
        add_node(symtab, node);
    else
        symtab = node;
}

// symbol reference
Index symToIdx(const char* key)
{
    SymTabNode* node = find_node(symtab, create_name(key));

    if(node != NULL)
        return node->idx;
    else
        return 0;   // error Var
}

// symbol reference
Value symToVal(const char*key)
{
    SymTabNode* node = find_node(symtab, create_name(key));
    Value val;

    if(node != NULL)
        val = getVar(&vm->vstore, node->idx);
    else {
        memset(&val, 0, sizeof(Value));
        val.type = ERROR;
    }

    return val;
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

void pushContext(const char* name)
{
    Context* cont = _alloc_ds(Context);
	cont->name = _copy_str(name);

	if(first != NULL) {
		last->next = cont;
		cont->prev = last;
		last = cont;
	}
	else {
		last = first = cont;
	}

}

void popContext()
{
    Context* cont = last;

    if(cont != NULL) {
        last = last->prev;
        if(last != NULL) {
			last->next = NULL;
		}
    }
}
