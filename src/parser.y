%debug
%defines
%locations

%{
#include <stdio.h>
#include "scanner.h"
%}

%union {
	char* data;
	int eol;
};

%token <data> DATA 
%token <eol> EOL

%define parse.error verbose
%locations

%%
start: /* nothing */
 | data EOL { }
 ;

data: DATA     { }
 ;
%%

void yyerror(const char *s)
{
  fprintf(stderr, "%s\n", s);
}
