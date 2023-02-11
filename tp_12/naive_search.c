
#include "naive_search.h"

int naive_search(char* text, char* pattern) {
    // On cherche pour chaque position dans le text si c'est une occurence de pattern
    for (long unsigned int i=0; i<strlen(text)-strlen(pattern); i++) {
        long unsigned int j = 0;
        while (j<strlen(pattern) && pattern[j] == text[i+j]) j++;
        if (j==strlen(pattern)) return i; // On à trouver une occurence, donc c'est la première et on return ça position dans le text
    }
    return -1; // Aucune occurence trouver
}