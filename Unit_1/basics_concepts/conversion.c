/* à compléter: entêtes */
#include <stdio.h>
#include <stdlib.h>


float celsius(float fahrenheit)
 {

    float celsiusRes = (5*(fahrenheit - 32)/9);
    return celsiusRes;

 }

int main(void)
{

    printf("------------------------- \n");
    printf("Fahrenheit \t Celsius \n\n");

    for (int i = 0; i <= 200; i+=20)
    {
        float celsiusRes = celsius(i);

        printf("%d \t\t %.1f \n", i, celsiusRes);
    }

    printf("------------------------- \n");

	return EXIT_SUCCESS;
}
