#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pgmio.h>
#include <time.h>
#include "allocation.h"
#include "traitement.h"

// fonction permettant d'afficher une de type image pgm.
void pgm_show(char *filename){
    // automate the command space.
    char command[256];
    snprintf(command, sizeof(command), "eog %s &", filename);
    system(command);
}

int main(void) {

    // Temps CPU écoulé au démarrage du main.
    clock_t start_time = clock(); 

    char *fileRead = "guadalest.pgm";
    // Variable qui sera le nouveau fichier copié de l'image.
    char *OutputFile = "guadalest_copie.pgm";

    pgm_t_image *struct_img1;
    struct_img1 = pgm_malloc(300,300);

    pgm_t_image *struct_img2;
    struct_img2 = pgm_read(fileRead);

    pgm_t_image *struct_img3;
    struct_img3 = pgm_malloc(512,512);
    
for (int i = 0; i < 5; i++)
{

    // extrait les informations sur la largeur et la hauteur de l'image, et retourne un pointeur vers un tableau de pixels (représentés par le type).
    pgm_solid(struct_img1, 0);
    // Ecrire la copie de l'image a partir de l'original.
    pgm_write(OutputFile, struct_img1);

    // NEGATIVE
    pgm_negative(struct_img1);
    // Ecraser par le nouveau vecteur de pixel.
    pgm_write(OutputFile, struct_img1);

    // TRESHOLD
    pgm_threshold(struct_img2, 120);
    pgm_write(OutputFile, struct_img2);

    // GRADIANT

    pgm_gradient(struct_img3);
    pgm_write(OutputFile, struct_img3);
    //pgm_show(OutputFile);

}
    // call the free function.
    pgm_free(struct_img1);
    pgm_free(struct_img2);
    pgm_free(struct_img3);

    clock_t end_time = clock(); 

    float elapsed_time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nTemps d'execution : %.3f secondes\n", elapsed_time);

    return EXIT_SUCCESS;
}