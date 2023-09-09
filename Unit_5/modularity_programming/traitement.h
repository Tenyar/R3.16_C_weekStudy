// Ceci est la garde pré-processeur pour éviter des erreurs de définitions multiples.
#ifndef TRAITEMENT_H_  /* convention classique: nom du module en majuscules, suivi de _H_ */
#define TRAITEMENT_H_

#define SEUIL1_PIXEL(valeur, seuil) (valeur < seuil) ? 0 : 255
#define SEUIL2_PIXEL(valeur, seuil) (valeur = (SEUIL1_PIXEL(valeur, seuil)))
#define DEBUG 1

// if DEBUG == 1
#if DEBUG 
#define AFFICHER_FONCTION(func) (printf("\nCalled function is : %s\n", func))
#else
// if DEBUG == 0 (pour ne pas avori d'erreur) mettre la fonction vide
#define AFFICHER_FONCTION(func)
#endif



/* contenu du fichier */
void pgm_solid(pgm_t_image * struct_img, pgm_t_pixel color);
void pgm_negative(pgm_t_image * struct_img);
void pgm_threshold(pgm_t_image * struct_img, pgm_t_pixel threshold);
void pgm_gradient(pgm_t_image * struct_img);
#endif /* MON_MODULE_H_ */



//gcc -std=c99 -Wall -Wextra -g -c -o allocation.o allocation.c
//kersuaar@pc-dg-025-03:~/Documents/R3.16/Unit_5/pgmStruct.git$ gcc -std=c99 -Wall -Wextra -g -c -o traitement.o traitement.c
//kersuaar@pc-dg-025-03:~/Documents/R3.16/Unit_5/pgmStruct.git$ gcc -std=c99 -Wall -Wextra -g -c -o main.o main.c
