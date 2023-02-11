
#include "rabin_karp.h"

// Fonction puissance
long unsigned int int_pow(long unsigned int a, int b) {
    if (b==0) return 1;
    if (b==1) return a;
    if (b%2 == 0) return int_pow(a*a, b/2);
    else return int_pow(a, (b-1))*a;
}

// Fonction de hash
int hash(char* text, int b, int size) {
    long unsigned int p = int_pow(2,31)-1;
    int s = 0;
    for (int i=0; i<size; i++) {
        s += text[i]*int_pow(b,size-(i+1));
    }
    s = s%p;
    return s;
}

// Rabin Karp
int_list_t rabin_karp_search(char* text, char* pattern) {
    int_list_t occ = create_empty_list();
    int b = 256;  // Taille de l'alphabet
    long unsigned int p = int_pow(2,31);  // grand nombre pour les modulos
    int sizePat = strlen(pattern);
    long unsigned int hp = hash(pattern, b, sizePat);  // hash du pattern
    long unsigned int ht = hash(text, b, sizePat);     // hash des sizePat premier caractères du text
    // Pour chaque position dans le text
    for (long unsigned int i=0; i<strlen(text)-sizePat; i++) {
        // Si les deux hash correspondent
        if (ht==hp) {
            // On vérifie si c'est bien une occurence
            int j = 0;
            while (j<sizePat && text[i+j] == pattern[j]) j++;
            if (j==sizePat) add(occ, i);  // Ajout de l'occurence dans occ
        }
        // Mise à jour du hash (pour la position suivante)
        ht = ((ht-text[i]*int_pow(b,sizePat-1))*b+text[i+sizePat])%(p-1);
    }
    return occ; // renvoie des occurence
}