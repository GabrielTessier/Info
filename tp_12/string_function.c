
#include "string_function.h"

int strcmp2(char* s1, char* s2) {
    int i = 0;
    while (s1[i] != 0 && s2[i] != 0) {
        // Vérification si il y a une différence entre s1 et s2
        if (s1[i] < s2[i]) return -1;
        if (s1[i] > s2[i]) return 1;
        i++;
    }
    if (s1[i] != 0) return -1;  // s1 plus grande que s2
    if (s2[i] != 0) return 1;   // s2 plus grande que s1
    return 0;  // Égaliter entre s1 et s2
}

int strlen2(char* s) {
    int i=0;
    while (s[i] != 0) i++;  // On parcourt s jusqu'a trouver '\0'
    return i;
}

char* strcpy2(char* dest, char* src){
    // La vérification que dest est assez grand est laisser à l'utilisateur de la fonction
    int i = 0;
    while (src[i] != 0) {
        dest[i] = src[i];  // Copy de chaque caractères de src dans dest
        i++;
    }
    dest[i] = 0;
    return dest;
}

char* strcat2(char* dest, char* src) {
    // La vérification que dest est assez grand est laisser à l'utilisateur de la fonction
    int n = strlen2(dest);
    int i = 0;
    while (src[i] != 0) {
        dest[i+n] = src[i];  // Ajout de chaque caractères de src à la fin de dest
        i++;
    }
    dest[i+n] = 0;

    return dest;
}