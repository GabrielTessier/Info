
#include "boyer_moore.h"

// Fonction qui renvoie un tableau des déplacements à éfectuer en fonction des carractères (et de leurs position)
int* create_mvt_list(char* pattern) {
    int sizePat = strlen(pattern);
    int nbChar = 256;  // Taille de l'alphabet
    int* list = malloc(sizeof(int)*sizePat*nbChar);  // tableau de taille sizePat*nbChar
    // Initialisation des cases du tableau à -1
    for (int i=0; i<sizePat*nbChar; i++) {
        list[i] = -1;
    }
    // Ajout des bonne valeurs dans le tableau
    for (int i=0; i<sizePat; i++) { // Pour chaque caractères de pattern
        for (int j=i; j<sizePat; j++) { // Pour chaque caractères suivant le caractères en cour de traitement
            list[j*nbChar + pattern[i]] = i;  // On met dans ça cases pour le caractères en cour de traitement la position du caractère en cour de traitement
        }
    }
    return list;
}

// Boyer Moore Horspool
int_list_t boyer_moore_search(char* text, char* pattern) {
    int_list_t occ = create_empty_list();
    int textSize = strlen(text);
    int sizePat = strlen(pattern);
    int* mv_list = create_mvt_list(pattern);
    int i = 0;
    // Tant qu'on à pas atteint la fin de text
    while (i<textSize-sizePat) {
        // On cherche le premier caractère qui pose problème en partant de la droite
        int j = sizePat-1;
        while (j>=0 && text[j+i] == pattern[j]) j--;
        // Si on trouve un caractères qui pose problème
        if (j>=0) {
            i += j-mv_list[j*256 + text[j+i]];  // On aplique le déplacement qui correspond
        } else { // Si on à trouver une occurence
            add(occ, i); // On l'ajoute à la liste des occurences
            i += sizePat; // on avance de la taille du pattern
        }
    }
    free(mv_list);
    return occ;  // On renvoie les occurences
}