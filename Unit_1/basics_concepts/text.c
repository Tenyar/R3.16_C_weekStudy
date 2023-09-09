#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int *p = malloc(1*sizeof(int));  // fill buffer with 0 (a.k.a. '\0')

	*p=12;

// Cette ligne affiche l'adresse mémoire à laquelle pointe p
	printf("%p\n",p); //%p pour afficher le pointer
	printf("%d\n",*p);
	printf("%p",&p); // Emplacement en mémoire du pointer P

    return EXIT_SUCCESS;
}
