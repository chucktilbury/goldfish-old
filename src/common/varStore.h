#ifndef VARIABLES_H
#define VARIABLES_H

void initVarStore();

void loadVarStore(FILE* fp);
void saveVarStore(FILE* fp);

Index createVar(ValType type);
Index assignVar(Index idx, Value* val);
Index assignVarName(Index vidx, Index sidx);
Index addVar(Value val);
Value* getVar(Index idx);
void delVar(Index idx);
const char* getVarName(Index idx);
void dumpVars(FILE* outf);

Value* resetVars();
Value* iterateVars();

#endif