#ifndef VMERRORS_H
#define VMERRORS_H

void fatalError(const char* fmt, ...);
void runtimeError(const char* fmt, ...);
void runtimeWarning(const char* fmt, ...);
int getErrors();
int getWarnings();

#endif