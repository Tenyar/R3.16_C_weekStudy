/* à compléter: entêtes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_LEN 64

int main(int argc,char *argv[4])
{   
    printf("\n\033[35;1m /!\\ One digit after the decimal point is the most !\033[0m \n");
    // (Lisibilité) pour l'opérateur (+, -, x, /).
    char operator = *argv[2];

    // If arguments given do not match the correct format.
    if ((argc != 4) || (*argv[1] <= '0' || *argv[1] >= '9') || (*argv[3] <= '0' || *argv[3] >= '9'))
    {
        printf("\n \033[31;1m [Error] you didn't select numbers to operate or did not select a proper operator. \033[0m ");
        return EXIT_FAILURE; // -1
    }

   // Code ascii des opérandes
   printf("\n------- Code ascii des operandes\n");
    printf("\033[32;1m arg1 : %d --> %s \n\033[0m", *argv[1], argv[1]);
    printf("\033[32;1m arg2 : %d --> %s \n\033[0m", *argv[2], argv[2]);
    printf("\033[32;1m arg3 : %d --> %s \n\033[0m", *argv[3], argv[3]);

    // Print String arguments.
   printf("------- Print String arguments\n");
    printf("\033[32;1m arg1 : %s \n\033[0m", argv[1]);
    printf("\033[32;1m arg3 : %s \n\033[0m", argv[3]);

    // String des arguments to Integer.
    float num1 = atof(argv[1]);
    float num2 = atof(argv[3]);
   printf("------- String des arguments to Integer\n");
    printf("\033[32;1m operande 1 : %.1f\n\033[0m", num1);
    printf("\033[32;1m operande 2 : %.1f\n\033[0m", num2);

    // Variable résultat.
    float result;
    switch (operator)
    {
    case '+':
        /* code */
        result = (num1 + num2);
        printf(" \n\n \033[34;1m Resultat de l'addition : %.1f\n \033[0m", result);
        break;

    case '-':
        /* code */
        result = (num1 - num2);
        printf(" \n\n \033[34;1m Resultat de la soustraction : %.1f\n \033[0m", result);
        break;
    
    case 'x':
        result = (num1 * num2);
        printf(" \n\n \033[34;1m Resultat de la multiplication : %.1f\n \033[0m", result);
        break;

    case '/':
        result = (num1 / num2);
        printf(" \n\n \033[34;1m Resultat de la division : %.1f\n \033[0m", result);
        break;
    
    default:
        printf("\n \033[31;1m [Error] you didn't enter an appropriate operator.\033[0m \n");
        break;
    }

    printf("Name of programme %s \n\n", argv[0]);
    
	return EXIT_SUCCESS;
}
