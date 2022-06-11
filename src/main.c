
#include <stdio.h>
#include <stdint.h>

#include "parser.h"
#include "scanner.h"

extern FILE* outfile;

int main()
{
  outfile = stdout;
  open_file("test.txt");

  yyparse();

  close_file();

  return 0;
}
