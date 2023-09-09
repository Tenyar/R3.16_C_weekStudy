#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void permuter(int *adr_a, int *adr_b){
    // sauvegarde du pointeur sur a.
    int temp = *adr_a;
    *adr_a = *adr_b;
    *adr_b = temp;

}

int main(void) {

    int *ptr_a;
    int *ptr_b;
    /*int temp = 0;
    
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("temp = %d\n", temp);

    printf("---\n");

    temp = b;
    printf(" temp = b : %d\n", temp);
    b = a;
    printf(" b = a : %d\n", b);
    a = temp;
    printf(" a = temp : %d\n", a);*/

    ptr_a = (int *) malloc(1*sizeof(int));
    ptr_b = (int *) malloc(1*sizeof(int));
    
    *ptr_a = 1;
    *ptr_b = 2;

    // IMPORTANT !!! BONUS
    if (ptr_a && ptr_b) // si l'allocation à réussis et qu'il y a un entier dans les 2 @ mém
    {
    printf("avant permutation \n");
    printf("a = %d\n", *ptr_a);
    printf("b = %d\n", *ptr_b);

    permuter(ptr_a, ptr_b);

    printf("après permutation \n");
    printf("a = %d\n", *ptr_a);
    printf("b = %d\n", *ptr_b);

    // si malloc réussis pas, pas de free
    free(ptr_a);
    free(ptr_b);
    }

    return EXIT_SUCCESS;
}
