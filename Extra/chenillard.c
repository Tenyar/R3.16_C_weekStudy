#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// les deux états possibles d'une ampoule.
#define ON '*'
#define OFF '.'

#define NUM_LENGTH 10

#define _POSIX_C_SOURCE 199309L  // nanosleep in POSIX.1b (real-time extensions)
#include <time.h>

static void ms_sleep(const unsigned long long int ms)
{
	struct timespec delay = {
		.tv_sec = ms / 1000,
		.tv_nsec = ms % 1000 * 1000000,
	};
	nanosleep(&delay, NULL);
}

void mv_chenillard(int length, char chenillard[NUM_LENGTH])
{

    for (int i = 0; i < length; i++)
    {
        chenillard[i] = ON;
        if (i > 0)
        {
            chenillard[i-1] = OFF;
        }
        printf("\r%s", chenillard);
        fflush(stdout);
        ms_sleep(100);
    }
    
}

int main()
{   
    // Initialisation du chennilard.
    char chenillard[NUM_LENGTH+1] = {'\0'}; // + 1 for the null terminator
    printf("\n");

    for (int i = 0; i < NUM_LENGTH; i++)
    {
        chenillard[i] = OFF;
    }
    
    printf("%s", chenillard);

    // Print new line at the end of the animation.
    mv_chenillard(NUM_LENGTH, chenillard);
    printf("\n");

    return EXIT_SUCCESS;
}
//  COMMAND COMPILE POWER-SHELL : gcc -std=c99 -Wall -Wextra -g -o pascal pascal.c