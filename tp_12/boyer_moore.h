
#ifndef BOYER_MOORE_H
#define BOYER_MOORE_H

#include <string.h>
#include "int_list.h"

int* create_mvt_list(char* pattern);
int_list_t boyer_moore_search(char* text, char* pattern);

#endif // BOYER_MOORE_H