/* à compléter: entêtes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void bin2dec(char bin[], char dec[]){
    
    int chaineBinaire = strlen(bin);
    int decimal = 0;
    printf("\nchaine binaire lenth : %d\n", chaineBinaire);
    //parcourir à l'envers pour convertire.
    // chaine binaire - 1 pour ne pas inclure le '\0' (NULL) qui est à la fin de la chaine.
    for (int i = chaineBinaire-1; i >= 0; i--)
    {

        printf("i : %d\n", i);
            
        printf("chaineBinaire - i : %d\n", ((chaineBinaire - 1) - i));

            if (bin[i] == '1')
            {
                
                // 2 puissance l'index
                // Sachant que i = 7 et que chainebinaire = 8 il faut donc soustraire -1 a chaineBinaire faire correctement les conversion
                // Sinon on à un nombre d'avance dans la conversion à chaque fois..
                decimal += pow(2, (chaineBinaire - 1) - i);
            }
            else if (bin[i] != '0' && bin[i] != '1')
            {
                printf("\n \033[31;1m [Error] You must enter only binary numbers. \033[0m ");
                exit(0); // -1
            }
    }

    printf("\nDecimale : %d\n", decimal);

    //The string "<%d>" is stored into buffer instead of printing on stdout
    sprintf(dec, "<%d>10", decimal);

    //dec = itoa(decimal, dec, 10); // radix : 10 for decimal, 2 for binary, 16 for hexadecimal.
    printf("\n<%s>2 = %s\n\n", bin, dec); // (%binary[0] ou binary) est déjà une adresse (pointeur) vers la première caractère du tableau
}

int main(void)
{   
    // Binary given to be converted.
    char binary[32];
    char decimal[32];

    printf("\n\n\033[35;1m /!\\ Donner un nombre en binaire : \033[0m \n");
    scanf ("%s", binary);

    bin2dec(binary, decimal);

	return EXIT_SUCCESS; // 0
}
