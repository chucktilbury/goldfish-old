#ifndef ERRORS_H
#define ERRORS_H

void error(const char* fmt, ...);
void warning(const char* fmt, ...);
void fatal(const char* fmt, ...);

int get_errors();
int get_warnings();

#endif