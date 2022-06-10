
#include <stdio.h>
#include "parser.h"

int main()
{
  printf("> "); 
  yyparse();
  return 0;
}
