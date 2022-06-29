/*
 * This is the complete grammar for the NOP programming language.
 */

%debug
%defines
%locations

%{

#include "gas.h"
#include <stdarg.h>

// defined by flex
extern int yylex(void);
extern int yyparse(void);
extern FILE *yyin;
void yyerror(const char* s)
{
    syntaxError("%s", s);
}

// defined in main.c
//extern Symbol* sym_table;
extern int error_count;
void syntaxError(const char*, ...);

static bool first_flag = true;

%}

%define parse.error verbose
%locations

%union {
    Value literal;
    int opcode;
    int type;
    int reg;
    char* symbol;
    char* qstr;
    void* usr;
};

%token <symbol> TOK_SYMBOL
%token <literal> TOK_UNUM
%token <literal> TOK_INUM
%token <literal> TOK_FNUM
%token <literal> TOK_TRUE TOK_FALSE
%type <literal> expression expression_factor expr_parameter
%type <literal> type_name type_specifier bool_value
%type <symbol> data_declaration data_definition

%token <usr> TOK_USRTYPE
%token <qstr> TOK_QSTR

%token <type> TOK_INT TOK_FLOAT TOK_UINT TOK_STRING
%token <type> TOK_ADDR TOK_BOOL TOK_LINE

%token <opcode> TOK_ABORT TOK_EXIT TOK_NOP TOK_CALL TOK_RCALL TOK_TRAP
%token <opcode> TOK_RETURN TOK_JMP TOK_RJMP TOK_BR TOK_RBR
%token <opcode> TOK_PUSH TOK_POP TOK_LOAD TOK_DIV TOK_MOD
%token <opcode> TOK_STORE TOK_NOT TOK_EQ TOK_NEQ TOK_LEQ
%token <opcode> TOK_GEQ TOK_LESS TOK_GTR TOK_NEG TOK_ADD TOK_SUB TOK_MUL

%token <reg> TOK_R0 TOK_R1 TOK_R2 TOK_R3 TOK_R4 TOK_R5 TOK_R6 TOK_R7
%token <reg> TOK_R8 TOK_R9 TOK_R10 TOK_R11 TOK_R12 TOK_R13 TOK_R14 TOK_R15
%type <reg> register

%token TOK_CONST

%right '='
%left '+' '-'
%left '*' '/' '%'
%left NEGATE

%%
program
    :  {
        // Emit stuff at the beginning of the file.
        Value val;
        val.type = ADDRESS;
        val.isAssigned = true;
        val.data.addr = getLabelAddr();
        Index vidx = addVar(val);
        const char* str = "__start_address__";
        Index sidx = addStr(str);
        assignVarName(vidx, sidx);
        addSym(str, vidx);
    } module
    ;

module
    : module_item_list {
        // Emit stuff at the end of the file.
        Value val;
        val.type = ADDRESS;
        val.isAssigned = true;
        val.data.addr = getLabelAddr();
        Index vidx = addVar(val);
        const char* str = "__end_address__";
        Index sidx = addStr(str);
        assignVarName(vidx, sidx);
        addSym(str, vidx);

        WRITE_VM_8(OP_NOP);
    }
    ;

module_item_list
    : module_item
    | module_item_list module_item
    ;

module_item
    : instruction
    | data_definition
    | TOK_SYMBOL ':' {
        Index idx = symToIdx($1);
        if(idx == 0) {
            Value val;
            val.type = ADDRESS;
            val.isAssigned = true;
            val.isConst = true;
            val.data.addr = getLabelAddr();
            Index vidx = addVar(val);
            Index sidx = addStr($1);
            fprintf(stderr, "define new label: %s:%d: sidx: %d\n", $1, vidx, sidx);
            assignVarName(vidx, sidx);
            addSym($1, vidx);
        }
        else {
            Value* val = getVar(idx);
            if(val->type != ADDRESS)
                syntaxError("symbol \"%s\" has already been defined as a %s", $1, valTypeToStr(val->type));
            else if(val->isAssigned)
                syntaxError("label \"%s\" has already been assigned", $1);
            else {
                Value v;
                v.type = ADDRESS;
                v.data.addr = getInstrLen();
                v.isConst = true;
                assignVar(idx, &v); // isAssigned = true...
            }

            fprintf(stderr, "define existing label: %s:%d: addr: %d\n", $1, idx, val->data.addr);
        }
    }
    | TOK_LINE TOK_INUM TOK_QSTR {
        set_line_no($2.data.inum);
        set_file_name($3);
        if(first_flag) {
            //vm->fname = _copy_str($3);
            setVmName($3);
            first_flag = false;
        }
    }
    ;

instruction
    : TOK_EXIT { WRITE_VM_8(OP_EXIT); }
    | TOK_RETURN { WRITE_VM_8(OP_RETURN); }
    | TOK_NOP { WRITE_VM_8(OP_NOP); }
    | class1_instr
    | class2_instr
    | class3_instr
    | class4_instr
    | class5_instr
    | class6_instr
    | class7_instr
    | class8_instr
    ;

register
    : TOK_R0
    | TOK_R1
    | TOK_R2
    | TOK_R3
    | TOK_R4
    | TOK_R5
    | TOK_R6
    | TOK_R7
    | TOK_R8
    | TOK_R9
    | TOK_R10
    | TOK_R11
    | TOK_R12
    | TOK_R13
    | TOK_R14
    | TOK_R15
    ;

    /* binary arithmetic into register */
class1_instr
    : TOK_ADD register ',' register ',' register {
        WRITE_VM_8(OP_ADD);
        WRITE_VM_16((($2 & 0x0F) << 8)|(($4 & 0xF) << 4)|($6 & 0xF));
    }
    | TOK_SUB register ',' register ',' register {
        WRITE_VM_8(OP_SUB);
        WRITE_VM_16((($2 & 0x0F) << 8)|(($4 & 0xF) << 4)|($6 & 0xF));
    }
    | TOK_MUL register ',' register ',' register {
        WRITE_VM_8(OP_MUL);
        WRITE_VM_16((($2 & 0x0F) << 8)|(($4 & 0xF) << 4)|($6 & 0xF));
    }
    | TOK_DIV register ',' register ',' register {
        WRITE_VM_8(OP_DIV);
        WRITE_VM_16((($2 & 0x0F) << 8)|(($4 & 0xF) << 4)|($6 & 0xF));
    }
    | TOK_MOD register ',' register ',' register {
        WRITE_VM_8(OP_MOD);
        WRITE_VM_16((($2 & 0x0F) << 8)|(($4 & 0xF) << 4)|($6 & 0xF));
    }
    ;

    /* binary compare into zero flag */
class2_instr
    : TOK_NEG register ',' register {
        WRITE_VM_8(OP_NEG);
        WRITE_VM_8((($2 & 0xF) << 4)|($4 & 0xF));
    }
    | TOK_EQ register ',' register {
        WRITE_VM_8(OP_EQ);
        WRITE_VM_8((($2 & 0xF) << 4)|($4 & 0xF));
    }
    | TOK_NEQ register ',' register {
        WRITE_VM_8(OP_NEQ);
        WRITE_VM_8((($2 & 0xF) << 4)|($4 & 0xF));
    }
    | TOK_LEQ register ',' register {
        WRITE_VM_8(OP_LEQ);
        WRITE_VM_8((($2 & 0xF) << 4)|($4 & 0xF));
    }
    | TOK_GEQ register ',' register {
        WRITE_VM_8(OP_GEQ);
        WRITE_VM_8((($2 & 0xF) << 4)|($4 & 0xF));
    }
    | TOK_LESS register ',' register {
        WRITE_VM_8(OP_LESS);
        WRITE_VM_8((($2 & 0xF) << 4)|($4 & 0xF));
    }
    | TOK_GTR register ',' register {
        WRITE_VM_8(OP_GTR);
        WRITE_VM_8((($2 & 0xF) << 4)|($4 & 0xF));
    }
    ;

    /* one register parm */
class3_instr
    : TOK_NOT register {
        WRITE_VM_8(OP_NOT);
        WRITE_VM_8(($2 & 0xF));
    }
    | TOK_POP register {
        WRITE_VM_8(OP_POP);
        WRITE_VM_8(($2 & 0xF));
    }
    ;


    /* Register parameter that must contain an address or an offset */
class4_instr
    : TOK_ABORT register {
        WRITE_VM_8(OP_ABORTR);
        WRITE_VM_8(($2 & 0xF));
    }
    | TOK_CALL register {
        WRITE_VM_8(OP_CALLR);
        WRITE_VM_8(($2 & 0xF));
    }
    | TOK_JMP register {
        WRITE_VM_8(OP_JMPR);
        WRITE_VM_8(($2 & 0xF));
    }
    | TOK_BR register {
        WRITE_VM_8(OP_BRR);
        WRITE_VM_8(($2 & 0xF));
    }
    | TOK_PUSH register {
        WRITE_VM_8(OP_PUSHR);
        WRITE_VM_8(($2 & 0xF));
    }
    ;

    /* references an operand from the varStore */
class5_instr
    : TOK_ABORT TOK_SYMBOL {
        WRITE_VM_8(OP_ABORT);
        Index idx = symToIdx($2);
        if(idx == 0)
            syntaxError("symbol \"%s\" has not been defined", $2);
        WRITE_VM_OBJ(Index, idx);
    }
    | TOK_PUSH TOK_SYMBOL {
        WRITE_VM_8(OP_PUSH);
        Index idx = symToIdx($2);
        if(idx == 0)
            syntaxError("symbol \"%s\" has not been defined", $2);
        WRITE_VM_OBJ(Index, idx);
    }
    | TOK_CALL TOK_SYMBOL {
        WRITE_VM_8(OP_CALL);
        Index idx = symToIdx($2);
        if(idx == 0) {
            Value val;
            val.type = ADDRESS;
            val.data.addr = 0;
            val.isAssigned = false;
            idx = addVar(val);
            fprintf(stderr, "pre-add call symbol: %s:%d\n", $2, idx);
            assignVarName(idx, addStr($2));
            addSym($2, idx);
        }
        WRITE_VM_OBJ(Index, idx);
    }
    | TOK_JMP TOK_SYMBOL {
        WRITE_VM_8(OP_JMP);
        Index idx = symToIdx($2);
        if(idx == 0) {
            Value val;
            val.type = ADDRESS;
            val.data.addr = 0;
            val.isAssigned = false;
            idx = addVar(val);
            fprintf(stderr, "pre-add jmp symbol: %s:%d\n", $2, idx);
            assignVarName(idx, addStr($2));
            addSym($2, idx);
        }
        WRITE_VM_OBJ(Index, idx);
    }
    | TOK_BR TOK_SYMBOL {
        WRITE_VM_8(OP_BR);
        Index idx = symToIdx($2);
        if(idx == 0) {
            Value val;
            val.type = ADDRESS;
            val.data.addr = 0;
            val.isAssigned = false;
            idx = addVar(val);
            fprintf(stderr, "pre-add br symbol: %s:%d\n", $2, idx);
            assignVarName(idx, addStr($2));
            addSym($2, idx);
        }
        WRITE_VM_OBJ(Index, idx);
    }
    ;

    /* If there is no type coersion, then just take the largest one. */
expr_parameter
    : expression { $$ = $1; }
    | '(' type_name ')' expression {
        $$ = castValue($2.type, $4, true);
    }
    ;

    /* literal value parameter that must have an address or an address offset */
class6_instr
    : TOK_ABORT expr_parameter {
        WRITE_VM_8(OP_ABORTI);
        WRITE_VM_OBJ(Value, $2);
    }
    | TOK_CALL expr_parameter {
        WRITE_VM_8(OP_CALLI);
        WRITE_VM_OBJ(Value, $2);
    }
    | TOK_JMP expr_parameter {
        WRITE_VM_8(OP_JMPI);
        WRITE_VM_OBJ(Value, $2);
    }
    | TOK_BR expr_parameter {
        WRITE_VM_8(OP_BRI);
        WRITE_VM_OBJ(Value, $2);
    }
    | TOK_PUSH expr_parameter {
        WRITE_VM_8(OP_PUSHI);
        WRITE_VM_OBJ(Value, $2);
    }
    ;

    /* Numeric literal as parameter */
class7_instr
    : TOK_TRAP TOK_UNUM {
        WRITE_VM_8(OP_TRAP);
        Value v = castValue(UINT, $2, true);
        WRITE_VM_16(v.data.unum);
    }
    | TOK_TRAP TOK_INUM {
        WRITE_VM_8(OP_TRAP);
        Value v = castValue(UINT, $2, true);
        WRITE_VM_16(v.data.unum);
    }
    ;

    /* moving data in and out of registers */
class8_instr
    : TOK_LOAD register ',' register {
        WRITE_VM_8(OP_LOADR);
        WRITE_VM_8((($2 & 0xF) << 4)|($4 & 0xF));
    }
    | TOK_LOAD register ',' TOK_SYMBOL {
        Index idx = symToIdx($4);
        fprintf(stderr, "reference to load symbol: %s:%d\n", $4, idx);
        if(idx == 0)
            syntaxError("symbol \"%s\" has not been defined", $4);
        else {
            WRITE_VM_8(OP_LOAD);
            WRITE_VM_8(($2 & 0xF));
            WRITE_VM_OBJ(Index, idx);
        }
    }
    | TOK_LOAD register ',' expr_parameter {
        WRITE_VM_8(OP_LOADI);
        WRITE_VM_8(($2 & 0xF));
        WRITE_VM_OBJ(Value, $4);
    }
    | TOK_STORE TOK_SYMBOL ',' register {
        Index idx = symToIdx($2);
        fprintf(stderr, "reference to store symbol: %s:%d\n", $2, idx);
        if(idx == 0)
            syntaxError("symbol \"%s\" has not been defined", $4);
        else {
            WRITE_VM_8(OP_STORE);
            WRITE_VM_OBJ(Index, idx);
            WRITE_VM_8(($4 & 0xF));
        }
    }
    ;

type_name
    : TOK_INT {
        Value val;
        val.type = $1;
        val.isAssigned = false;
        $$ = val;
    }
    | TOK_UINT {
        Value val;
        val.type = $1;
        val.isAssigned = false;
        $$ = val;
    }
    | TOK_FLOAT {
        Value val;
        val.type = $1;
        val.isAssigned = false;
        $$ = val;
    }
    | TOK_BOOL {
        Value val;
        val.type = $1;
        val.isAssigned = false;
        $$ = val;
    }
    | TOK_ADDR {
        Value val;
        val.type = $1;
        val.isAssigned = false;
        $$ = val;
    }
    | TOK_STRING {
        Value val;
        val.type = $1;
        val.isAssigned = false;
        $$ = val;
    }
    ;

type_specifier
    : TOK_CONST type_name {
        $2.isConst = true;
        $$ = $2;
    }
    | type_name {
        $$ = $1;
    }
    ;

data_declaration
    : type_specifier TOK_SYMBOL {
        Index idx = addVar($1);
        fprintf(stderr, "adding symbol: %s:%d\n", $2, idx);
        addSym($2, idx);
        assignVarName(idx, addStr($2));
        $$ = $2;
    }
    ;

data_definition
    : data_declaration '=' expression {
        Value* val = symToVal($1);
        Value tmp = castValue(val->type, $3, $3.isConst);
        copyValue(val, &tmp);
    }
    | data_declaration '=' bool_value {
        Value* val = symToVal($1);
        if(val->type != BOOL)
            syntaxError("attempt to assign a BOOL value to a %s", valTypeToStr(val->type));
        else
            val->data.boolean = $3.data.boolean;
    }
    | data_declaration '=' TOK_QSTR {
        Value* val = symToVal($1);
        if(val->type != STRING)
            syntaxError("attempt to assign a STRING value to a %s", valTypeToStr(val->type));
        else
            val->data.str = addStr(preformat_str($3));
    }
    ;

bool_value
    : TOK_TRUE {}
    | TOK_FALSE {}
    ;

expression_factor
    : TOK_UNUM {}
    | TOK_INUM {}
    | TOK_FNUM {}
    | TOK_USRTYPE {}
    ;

expression
    : expression_factor
    | expression '+' expression { }
    | expression '-' expression { }
    | expression '*' expression { }
    | expression '/' expression { }
    | expression '%' expression { }
    | '-' expression %prec NEGATE { }
    | '(' expression ')' { }
    ;

%%
