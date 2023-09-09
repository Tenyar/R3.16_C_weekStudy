#define _POSIX_C_SOURCE 200809L  // getline in POSIX.1-2008

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void putchars(unsigned int repeat, char ch) {
    for (unsigned int i = 0; i < repeat; i++) {
        putchar(ch); // print the character.
    }
}


int main(int argc, char *argv[]) {

    // poiyr ne pas utiliser argc.
    (void)argc;

	// variables
    int hauteur = atoi(argv[1]);
    int etoile = 1;
    int espacement = hauteur-1;

    for (int i = 0; i < hauteur; i++)
    {
        putchars(espacement, ' ');
        putchars(etoile, argv[2][0]); // prendre l'argument 2 premier index (soit la première lettre)

        printf("\n");

        etoile += 2;
        espacement--;
    }
    
    return EXIT_SUCCESS;
}

 /* Old way not good
 
 // variables
    // pour espaces
    int j = repeat;
    int k = 0;
    // pour les étoiles "*"
    int point = 1;
    int incremPoint = 0;

    for (int i = 0; i < repeat; i++)
    {
        k = 0;
        // Boucle pour nombre d'espace du haut en bas (décrémentation).
        while(k < j)
        {
             printf(" ");
             k++;
        }

        while (incremPoint != point)
        {
        printf("*");

        incremPoint++;
        }

        printf("\n");
        incremPoint = 0;
        point += 2;
        j--;
    }*/