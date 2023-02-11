
#include "test.h"

void sum(const char* x, const char* y, char* result) {
    int a = atoi(x);  // char -> int
    int b = atoi(y);  // char -> int
    sprintf(result, "%d", a+b);  // Fait le calcul et le print dans result
}

int main() {
    printf("Question 1 : \n");
    for (int i=0; i<256; i++) {
        printf("%c", i);
    }
    printf("\n");
    

    printf("\nQuestion 2 : \n");
    char s1[] = "azertyuiop";
    char s2[] = "azertyuiop";

    printf("s1==s2 -> %d, strcmp(s1,s2) -> %d\n", s1==s2, strcmp(s1,s2));


    printf("\nQuestion 3-4 : \n");
    char* s3 = malloc(sizeof(char)*256);
    for (int i=1; i<256; i++) {  // On retire le 0
        s3[i-1] = i;
    }
    s3[255] = '\0';
    printf("%s\n", s3);
    free(s3);


    printf("\nQuestion 5 : \n");
    char* s4 = malloc(sizeof(char)*('z'-'A'+2));  // On prend le bon nombre de caractères
    for (int i=0; i<'z'-'A'+1; i++) {
        s4[i] = i+'A';
    }
    s4['z'-'A'+1] = '\0';
    printf("%s\n", s4);
    free(s4);


    printf("\nQuestion 7-8 : \n");
    printf("%d, %d, %d\n", strcmp2("aze", "aae"), strcmp2("aze", "aze"), strcmp2("aae", "aze"));

    printf("%d\n", strlen2("azertyuiop"));

    char* s5 = malloc(sizeof(char)*(33));
    for (int i=0; i<5; i++) {
        s5[i] = 'a';
    }
    s5[5] = 0;
    printf("%s\n", strcat2(s5, "azert"));
    free(s5);


    printf("\nQuestion 9 : \n");
    char* s6 = malloc(sizeof(char)*(33));
    sum("5","7",s6);
    printf("%s\n", s6);
    free(s6);
    

    printf("\nQuestion 11-12-13-14 : \n");
    char text[] = "azertyuiopqsdfghjklmwxcvbnaqsdvjkoiuytrsdyl;,nbvfdertyuikjhrsxcjkluytrsdfiokfdsertyuiokjtrsqwxvblkhfdsdtyuil,nbvcduil;cdftyuikjvcdruiol,nbvfrt-èiolkjhfrtyiolnbvfrtiolkhft-yèuioljftè_olkr-èiolkj";
    printf("%d\n", naive_search(text, "qsd"));
    int_list_t occ = rabin_karp_search(text, "qsd");
    print_int_list(occ);
    free_list(occ);
    int_list_t occ2 = boyer_moore_search(text, "qsd");
    print_int_list(occ2);
    free_list(occ2);

    return 0;
}