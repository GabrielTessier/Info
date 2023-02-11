
#ifndef RABIN_KARP_H
#define RABIN_KARP_H

#include <string.h>
#include "int_list.h"

long unsigned int int_pow(long unsigned int a, int b);
int hash(char* text, int b, int size);
int_list_t rabin_karp_search(char* text, char* pattern);

#endif // RABIN_KARP_H