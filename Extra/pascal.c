/* à compléter: entêtes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Fonction qui libère l'espace dynamiquement alloué des pointeurs.
void pascal_free(int profondeur, int** ptr){

    printf("\n\nPASCAL FREE APPELER !!!!\n\n");

    int i = 0;
    // On libères tout les pointeurs vers chaque monômes
    while (i <= profondeur)
    {
        free(ptr[i]);
        i++;
    }
    // Puis on libère le pointeurs qui les englobais.
    free(ptr);
}

// Fonction qui alloue de la place dynamiquement en mémoire.
int** pascal_malloc(int profondeur){

    int** triangle;
    // On alloue + 1 en profondeur car la première ligne ne compte pas si on parle des coéfficients des monômes.
    triangle = (int**) malloc((profondeur + 1) * sizeof(int*));

    // Regarde si l'allocation dynamique c'est effectuée.
    if (!triangle) return 0;
    
    // Pour chaque ligne allant jusuqu'a 'n' on alloue n+1 case en mémoire.
    for (int i = 0; i <= (profondeur + 1); i++)
    {
        triangle[i] = (int*) malloc((i+1) * sizeof(int));

        // i est donc le total de lignes ajouter jusqu'a 'n' avant l'appel de cette fonction.
        if (!triangle[i]){
            printf("\033[31;1m [Error] Memory allocation failed for row number %d.\033[0m", i+1);
            pascal_free(i, triangle);
        }
    }

    // On retourne le tableau contenants tous les autres tableaux(pointeurs) vers les entiers.
    return triangle;
}

// Calcule toutes les valeurs des coefficients dans un triangle déjà alloué.
void pascal_fill(int profondeur, int** triangle){
    // if not i = 1 then i - 1 = -1 and this is undifined memory 'leak'.
    for (int i = 0; i <= profondeur; i++){

        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i) // soit j == 0 (début) soit j == i (fin).
            {
                triangle[i][j] = 1;
            }
            else
            {
                triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
            }
        }

    printf("Pascal_fill called.\n\n");
    }
}

void pascal_display(int profondeur, int **triangle)
{

    for (int i = 0; i <= profondeur; i++){

        for (int j = 0; j <= i; j++)
        {
          printf("%d\t",triangle[i][j]);
        }

    printf("\n");
    }

}

void pascal_display_binome(int profondeur, int **triangle)
{
    for (int i = 0; i <= profondeur; i++){

        for (int j = 0; j <= i; j++)
        {
          //n−1 : coeff [ n , i ] = coeff [ n − 1 , i − 1 ] + coeff [ n − 1 , i ] . 
        printf("(a + b)^%d = ", profondeur);
        }

    }
    
 
}


int main(int argc,char *argv[])
{   
    if (argc != 2) return EXIT_FAILURE;
    printf("\n\n DEBUT  !!!!\n\n");

    // On prend le 2ème arguments (celui après le nom de la fonction).
    int profondeur = atoi(argv[1]);
    if (profondeur <= 0) return EXIT_FAILURE;

    // On alloue dynamiquement de la place pour le pointeur global et pour les autres pointeurs inclus dedans.
    int** tab_ptr_1;
    tab_ptr_1 = pascal_malloc(profondeur);

    // Quick test to check if the malloc succeded and to see their @
    printf("\n\033[34;1m @ de ptr global : %p\033[0m", tab_ptr_1);
    for (int i = 1; i < profondeur+1; i++)
    {
        printf("\n\033[32;1m@ de ptr numero [%d] : %p\033[0m", i,tab_ptr_1[i]);
    }
    
    pascal_fill(profondeur, tab_ptr_1);
    pascal_display(profondeur, tab_ptr_1);
    pascal_free(profondeur, tab_ptr_1);

	return EXIT_SUCCESS;
}
