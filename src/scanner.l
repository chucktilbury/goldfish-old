%{
#include "parser.h"
%}

%%
.+              { yylval.data = yytext; return(DATA); }
\n              { return(EOL); }
%%
int yywrap(){ return 1;}
