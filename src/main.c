
#include "goldfish.h"
#include "parser.h"
#include "scanner.h"

extern FILE* outfile;

int main()
{
  outfile = stdout;
  open_file(_copy_str("test.txt"));

  yyparse();

  close_file();

  return 0;
}
