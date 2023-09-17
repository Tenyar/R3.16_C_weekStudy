#ifndef CHENILLARD_H_  /* convention classique: nom du module en majuscules, suivi de _H_ */
#define CHENILLARD_H_
// les deux états possibles d'une ampoule.
#define ON '*'
#define OFF '.'
#define NUM_LENGTH 16
// Combien d'ampoule pour les tests.
#define N_AMP 32
#define _POSIX_C_SOURCE 199309L  // nanosleep in POSIX.1b (real-time extensions)


#include <time.h>

// entier non signé sur 16 bits : https://en.cppreference.com/w/c/types/integer
typedef int16_t t_switch16;
typedef int32_t t_switch32;

static void ms_sleep(const unsigned long long int ms)
{
	struct timespec delay = {
		.tv_sec = ms / 1000,
		.tv_nsec = ms % 1000 * 1000000,
	};
	nanosleep(&delay, NULL);
}

#endif