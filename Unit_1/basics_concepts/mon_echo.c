/* à compléter: entêtes */
#include <stdlib.h>

int main(int argc, char *argv[])
{


	//argv[0] contient le nom de la commande, argv[i], pour i allant de 1 à argc-1, le ième argument.
	//Le programme echo (echo.c) illustre cela.
	// 1 pour enlever l'élément "./balbal" avant.
	for (int i = 1; i < argc; i++)
	{
	printf("%s ", argv[i]);
	}
	printf("\n");
	return EXIT_SUCCESS;
}
