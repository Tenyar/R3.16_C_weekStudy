#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int carre_copie(int n){
    return pow(n,2);
}

void carre_adresse(int *adr_n){
    *adr_n = pow(*adr_n, 2);
}

int main(void) {

    int n_copie = 3;
    printf("entier avant appel de la fonction: %d \n", n_copie);
    printf("entier retourner par l'appel de la fonction: %d \n", carre_copie(n_copie));
    printf("entier après appel de la fonction: %d \n", n_copie);

    printf("--------------------\n");

    int adr_entier = 3;

    printf("entier avant appel de la fonction: %d \n", adr_entier);
    // Exécuution de la fonction
    carre_adresse(&adr_entier);
    printf("entier après appel de la fonction: %d \n", adr_entier); // Au pointeur l'entier mis à la puissance 2

    return EXIT_SUCCESS;
}
