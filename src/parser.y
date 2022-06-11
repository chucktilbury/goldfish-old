%debug
%defines
%locations

%{

#include <stdio.h>
#include <stdint.h>

#include "scanner.h"

FILE* outfile = NULL;
#define EMIT(fmt, ...)  fprintf(outfile, fmt, ## __VA_ARGS__)

%}

%union {
	char* str;
	uint64_t unum;
	int64_t inum;
	double fnum;
};

%token BREAK CASE CONTINUE CONST DEFAULT
%token DO ELSE FOR IF RETURN SWITCH IMPORT
%token NAMESPACE CLASS STRUCT WHILE
%token INT8 INT16 INT32 INT64
%token UINT8 UINT16 UINT32 UINT64
%token DOUBLE FLOAT NOTHING STRING
%token BOOL TRUE FALSE IN YIELD EXIT
%token EQU NEQU LORE GORE OR AND
%token TRY EXCEPT RAISE CTOR DTOR
%token PUBLIC PRIVATE PROTECTED
%token <str> SYMBOL
%token <inum> INUM;
%token <unum> UNUM;
%token <fnum> FNUM;
%token <str> STRG;

%define parse.error verbose
%locations

%right '='
%left OR
%left AND
%left EQU NEQU
%left LORE GORE '<' '>'
%left '+' '-'
%left '*' '/' '%'
%left NEGATE
%%

module
	: {
		// emit things before the input
		EMIT("before everything\n");
	} module_list {
		// emit things after the input
		EMIT("after everything\n");
	}
	;

module_list
	: module_item
	| module_list module_item
	;

module_item
	: import_statement
	| module_definition_item
	;

module_definition_item
	: class_definition
	| data_definition
	| func_definition
	| namespace_definition
	;

module_definition_list
	: module_definition_item
	| module_definition_list module_definition_item
	;

compound_name
	: SYMBOL {}
	| SYMBOL '.' SYMBOL {}
	;

import_statement
	: IMPORT SYMBOL {}
	;

namespace_definition
	: NAMESPACE SYMBOL '{' module_definition_list '}' {}
	| NAMESPACE SYMBOL '{'  '}' {}
	;

class_definition
	: CLASS SYMBOL '{' class_definition_list '}' {}
	| CLASS SYMBOL '{' '}' {}
	;

class_definition_list
	: class_definition_item
	| class_definition_list class_definition_item
	;

scope_operator
	: PRIVATE {}
	| PUBLIC {}
	| PROTECTED {}
	;

class_definition_item
	: symbol_declaration
	| func_declaration
	| struct_declaration
	| scope_operator
	| constructor_decl
	| destructor_decl
	;

type_name
	: INT8 {}
	| INT16 {}
	| INT32 {}
	| INT64 {}
	| UINT8 {}
	| UINT16 {}
	| UINT32 {}
	| UINT64 {}
	| DOUBLE {}
	| FLOAT {}
	| STRING {}
	| BOOL {}
	| NOTHING {}
	| compound_name {}
	;

symbol_type
	: type_name SYMBOL {}
	;

constructor_decl
	: CTOR '(' parameter_decl_list ')' {}
	;

destructor_decl
	: DTOR {}
	;

struct_declaration
	: STRUCT SYMBOL '{' struct_body '}' {}
	;

struct_body
	: symbol_declaration
	| struct_body symbol_declaration
	;

symbol_declaration
	: symbol_type
	| CONST symbol_type {}
	;

parameter_decl_list
	: /* empty */
	| symbol_type
	| parameter_decl_list ',' symbol_type
	;

func_declaration
	: symbol_type '(' parameter_decl_list ')' {}
	;

data_definition
	: symbol_declaration
	| symbol_declaration '=' expression {}
	;

func_definition
	: type_name compound_name '(' parameter_decl_list ')' '{' func_body_statement_list '}' {}
	| type_name compound_name '(' parameter_decl_list ')' '{' '}' {}
	| type_name compound_name ':' SYMBOL '(' parameter_decl_list ')' '{' '}' {}
	| type_name compound_name ':' SYMBOL '(' parameter_decl_list ')' '{' func_body_statement_list '}' {}
	| compound_name ':' CTOR '(' parameter_decl_list ')' '{' '}' {}
	| compound_name ':' CTOR '(' parameter_decl_list ')' '{' func_body_statement_list '}' {}
	| compound_name ':' DTOR '{' '}' {}
	| compound_name ':' DTOR '{' func_body_statement_list '}' {}
	;

func_body_statement
	: data_definition {}
	| compound_name '=' expression {}
	| if_statement {}
	| for_statement {}
	| while_statement {}
	| switch_statement {}
	| do_statement {}
	| try_statement {}
	| func_reference {}
	| RAISE '(' expression ')' {}
	| RETURN {}
	| RETURN '(' expression ')' {}
	| EXIT '(' expression ')' {}
	;

func_body_statement_list
	: func_body_statement
	| func_body_statement_list func_body_statement

loop_body_statement
	: func_body_statement
	| BREAK {}
	| CONTINUE {}
	| YIELD {}
	;

loop_body_statement_list
	: loop_body_statement
	| loop_body_statement_list loop_body_statement
	;

func_reference
	: compound_name '(' expression_list ')' {}
	;

except_clause
	: EXCEPT '(' compound_name ')' '{' func_body_statement_list '}' {}
	;

except_clause_intermediate_list
	: except_clause
	| except_clause_intermediate_list except_clause
	;

except_clause_final
	: EXCEPT '('  ')' '{' func_body_statement_list '}' {}
	| EXCEPT '{' func_body_statement_list '}' {}
	;

except_clause_list
	: except_clause_intermediate_list
	| except_clause_intermediate_list except_clause_final
	| except_clause_final
	;

try_statement
	: TRY '{' func_body_statement_list '}' except_clause_list {}
	;

else_clause
	: ELSE '(' expression ')' '{' func_body_statement_list '}' {}
	;

else_clause_intermediate_list
	: else_clause
	| else_clause_intermediate_list else_clause
	;

else_clause_final
	: ELSE '(' ')' '{' func_body_statement_list '}' {}
	| ELSE '{' func_body_statement_list '}' {}
	;

else_clause_list
	: else_clause_intermediate_list
	| else_clause_intermediate_list else_clause_final
	| else_clause_final
	;

if_clause
	: IF '(' expression ')' '{' func_body_statement_list '}' {}
	;

if_statement
	: if_clause
	| if_clause else_clause_list
	;

for_statement
	: FOR '(' compound_name IN expression ')' '{' loop_body_statement_list '}'
	;

while_statement
	: WHILE '(' expression ')' '{' loop_body_statement_list '}'
	;

case_clause
	: CASE constant_expression '{' func_body_statement_list '}' {}
	;

case_clause_intermediate_list
	: case_clause
	| case_clause_intermediate_list case_clause
	;

case_clause_list
	: case_clause_intermediate_list
	| case_clause_intermediate_list DEFAULT '{' func_body_statement_list '}' {}
	;

switch_statement
	: SWITCH '(' compound_name ')' '{' case_clause_list '}' {}
	;

do_statement
	: DO '{' loop_body_statement_list '}' WHILE '(' expression ')'
	;

constant_expression
	: UNUM {}
	| INUM {}
	| FNUM {}
	| TRUE {}
	| FALSE {}
	| STRG { /* string literals are formatted */ }
	;

expression_factor
	: constant_expression
	| func_reference {}
	| compound_name {}
	;

expression
	: expression_factor {}
	| expression '+' expression {}
	| expression '-' expression {}
	| expression '*' expression {}
	| expression '/' expression {}
	| expression '%' expression {}
	| expression EQU expression {}
	| expression NEQU expression {}
	| expression LORE expression {}
	| expression GORE expression {}
	| expression OR expression {}
	| expression AND expression {}
	| expression '<' expression {}
	| expression '>' expression {}
    | '-' expression %prec NEGATE { }
    | '!' expression %prec NEGATE { }
    | '(' expression ')' { }
	;

expression_list
	: /* empty */
	| expression {}
	| expression_list ',' expression {}
	;

%%

void yyerror(const char *s)
{
  fprintf(stderr, "%s\n", s);
}
