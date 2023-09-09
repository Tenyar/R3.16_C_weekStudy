/* à compléter: entêtes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_LEN 64

void reverseStr(char *str1)
 {
	// declare variable
	int i, len, temp;
	len = strlen(str1); // use strlen() to get the length of str string

	//use for loop to iterate the string
	for (i = 0; i < len/2; i++)
	{
		// temp variable use to temporary hold the string
		temp = str1[i];
		str1[i] = str1[len - i - 1];
		str1[len - i - 1] = temp;
	}

 }

int main(void)
{
	char orig[BUFFER_LEN] = "bonjour"; // initialiser au moment de la déclaration il y a "/0" a la fin
	// = {0}; is the universal zero initializer, C99 Standard 6.7.8.21
	char mirror[BUFFER_LEN] = {0};  // fill buffer with 0 (a.k.a. '\0') Mets automatiquement les 64 case a "/0" pour marquer la fin... Code Ascii 0 soit terminer la chaine et que sera ecraser par le nouveau mis dedans

	/* à compléter: corps de main */

	// boucle
	int index = strlen(orig)-1;
	for(int i = index; i >= 0; i--)
	{
		mirror[index - i] = orig [i]; 
	}
/*
	// Get current length of the string we need to copy
	int len = strlen(orig);

	// New variable for reversed string
	char origReverse[BUFFER_LEN] = {0};
	
	// Will copy 7 characters from array1 to array2
	strncpy(origReverse, orig, len);
	reverseStr(origReverse);
	strncpy(mirror, origReverse, len);


	// puts is used to print the string char array
	puts(mirror);
	// Or
*/

	printf("%s \n", mirror);
	/*int *p = malloc(1*sizeof(int));0};  // fill buffer with 0 (a.k.a. '\0')

	*p=12;

	printf("%p\n",p); //%p pour afficher le pointer
	printf("%d\n",*p);
	printf("%p",&p);*/

	return EXIT_SUCCESS;
}
