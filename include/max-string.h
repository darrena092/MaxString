#pragma once

#include <string.h>

char* mstrcat(const char* a, const char *b);
char* mstrtrim(const char* input, const char* trim_set);
char* mstrsubstr(const char *input, int offset, size_t length);
char* mstrreplace(const char *input, char find, char replace);
char* mstrremove(const char *input, char garbage);
char** mstrsplit(const char *input, char delimiter, int* token_count);