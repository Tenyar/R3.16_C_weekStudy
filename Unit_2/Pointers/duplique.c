#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LEN 64

char *copier_chaine(char *str){

    char * ptr_duplique = malloc(BUFFER_LEN * sizeof(char)); // allocation dynamique

    // si l'allocation à réussis et qu'il y a un entier dans les 2 @ mém 
    if (ptr_duplique) 
    {
    strncpy(ptr_duplique, str, strlen(str)+1); //strlen(str) renvoie la taille total de la chaine de caractère
    }
    return ptr_duplique;
}

int main(void) {
        
    char original[] = "Ma super chaine a copier";
    char *copie;  // copie a allouer dynamiquement

    copie = copier_chaine(original);
    printf("original = %s \n", original);
    printf("copie = %s \n", copie); // just copie == copie[0]


    free(copie); // on free le malloc allouer dans la fonction
    return EXIT_SUCCESS;
}
