/* à compléter: entêtes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void dec2bin(char dec[], char bin[]){

    float decimal = atof(dec);
    int index = 0;
    
    //printf("\n\n%.0f\n\n", decimal);
    printf("\nDECIMALE : <%s>10\n", dec);
    
    while (decimal > 0)
    {
        decimal = decimal / 2;
        printf("\n%.0f\n", decimal);

        if (decimal != (int)decimal)
        {
            bin[index] = '1';
        }
        else
        {
            bin[index] = '0';
        }

        index++;

        // Round the number down.
        decimal = (int)decimal;
    }

    // Now reverse the binary to terminate the methode (get the final result) [remonter la flèche du bas vers le haut].
    int left = 0;
    int right = index - 1;
    while (right > left)
    {
        char temp = bin[left];

        bin[left] = bin[right];
        bin[right] = temp;

        left++;
        right--;
    }
        
    printf("\n<%s>10 = <%s>2\n", dec, bin);
}

int main(void)
{   
    // Binary given to be converted.
    // Added '\0' to not have "garbage values".
    char decimal[16] = {'\0'};
    char binary[16] = {'\0'};

    printf("\n\n\033[35;1m /!\\ Donner un nombre en decimale : \033[0m \n");
    scanf ("%s", decimal);

    dec2bin(decimal, binary);
	return EXIT_SUCCESS; // 0
}
