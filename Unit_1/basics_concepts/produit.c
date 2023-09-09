/* à compléter: entêtes */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/* à compléter: corps de main */

	// Integer variable that will store the number we get from the user
	int numberOne, numberTwo;

	printf("Programme qui multiplie 2 nombres \n");

	printf("Saisir un premier nombre : ");
	// get the user input
	// scanf a besoin d'une adresse mémoire pour savoir ou stocker la variable saisit.
	scanf("%d", &numberOne);

	printf("Saisir un deuxième nombre : ");
	// get the user input
	// scanf a besoin d'une adresse mémoire pour savoir ou stocker la variable saisit.
	scanf("%d", &numberTwo);

	// Make the multiplication
	int numberMulti; 
	numberMulti = numberOne * numberTwo;

	printf("%d x %d = %d \n", numberOne, numberTwo, numberMulti);
	return EXIT_SUCCESS;
}
