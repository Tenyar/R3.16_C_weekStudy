/* à compléter: entêtes */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/* à compléter: corps de main */

	// Integer variable that will store the number we get from the user
	int numberTable;


	printf("vous voulez la table de combien ? ");
	// get the user input
	scanf("%d", &numberTable);

    int i = 0;
    while (i <= 10)
    {
        int resultMulti = i * numberTable;
        printf("%d x %d = %d \n", i, numberTable, resultMulti);
        i++;
    }

	return EXIT_SUCCESS;
}
