
#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string_function.h"
#include "naive_search.h"
#include "int_list.h"
#include "rabin_karp.h"
#include "boyer_moore.h"

int strcmp2(char* s1, char* s2);
int strlen2(char* s);
char* strcpy2(char* dest, char* src);
char* strcat2(char* dest, char* src);
void sum(const char* x, const char* y, char* result);
int naive_search(char* text, char* pattern);

#endif // TEST_H