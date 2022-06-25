#ifndef STRUTILS_H
#define STRUTILS_H

#include "system.h"

typedef struct {
    char* list;
    size_t cap;
    size_t len;
} String;

String* createStr(const char* str);
const char* getStrStr(String* s);
void addStrStr(String* s, const char* str);
void addStrChar(String* s, char ch);
const char* format_str(VM* vm, const char* str);

#endif