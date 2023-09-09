#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pgmio.h>


// retourne l'@ de la zone mémoire allouée pour stocker les pixels.
pgm_t_image *pgm_malloc(size_t width, size_t height){

    //Malloc générale pour la structure
    pgm_t_image * ptr_struct;
    ptr_struct = malloc ((1 * sizeof(pgm_t_image)));

    if (ptr_struct == NULL)
    {
        printf("\nOut of memory!\n");
        return NULL;
    }

    // Allouer de la place pour l'image.
    ptr_struct->pixels = malloc ((width * height) * sizeof(pgm_t_pixel));
    // width * height = surface de l'image

    // Now save (initialise) both width and height
    ptr_struct->width = width;
    ptr_struct->height = height;

    if (ptr_struct->pixels == NULL)
    {
        printf("\nOut of memory!\n");
        free(ptr_struct);
        return NULL;
    }
    else
    {
        return ptr_struct;
    }
}

void pgm_solid(pgm_t_image * struct_img, pgm_t_pixel color){

    for (size_t i = 0; i < (struct_img->width * struct_img->height); i++)
    {
        struct_img->pixels[i] = color;
    }
    

}

void pgm_negative(pgm_t_image * struct_img){

    for (size_t i = 0; i < (struct_img->width * struct_img->height); i++)
    {
        int newcolor = UCHAR_MAX - struct_img->pixels[i];
        struct_img->pixels[i] = newcolor;
    }
    

}

void pgm_threshold(pgm_t_image * struct_img, pgm_t_pixel threshold){

    for (size_t i = 0; i < (struct_img->width * struct_img->height); i++)
    {
        if (struct_img->pixels[i] < threshold)
        {
            struct_img->pixels[i] = 0;
        }
        else
        {
            struct_img->pixels[i] = UCHAR_MAX;
        }
    }
}

void pgm_gradient(pgm_t_image * struct_img){

    for (size_t i = 0; i < (struct_img->width * struct_img->height); i++)
    {
        struct_img->pixels[i] = (i % struct_img->width) / (float) struct_img->width * PGM_PIXEL_MAX;
    }

}

// fonction permettant d'afficher une de type image pgm.
void pgm_show(char *filename){
    // automate the command space.
    char command[(int)strlen(filename) + 20];
    snprintf(command, sizeof(command), "eog %s", filename);
    system(command);
}

void pgm_free(pgm_t_image *struct_img){

    free(struct_img->pixels);
    free(struct_img);
}

int main(void) {
    char *fileRead = "guadalest.pgm";
    // Variable qui sera le nouveau fichier copié de l'image.
    char *OutputFile = "guadalest_copie.pgm";
    size_t width, height;

    pgm_t_image *struct_img1;
    // extrait les informations sur la largeur et la hauteur de l'image, et retourne un pointeur vers un tableau de pixels (représentés par le type).
    struct_img1 = pgm_malloc(300,300);

    // Ecrire la copie de l'image a partir de l'original.
    pgm_write(OutputFile, struct_img1);
    pgm_show(OutputFile);

    pgm_solid(struct_img1, 125);

    // Ecraser par le nouveau vecteur de pixel.
    pgm_write(OutputFile, struct_img1);
    pgm_show(OutputFile);

    // TRESHOLD
    pgm_t_image *struct_img2;
    struct_img2 = pgm_read(fileRead);
    pgm_threshold(struct_img2, 120);
    pgm_write(OutputFile, struct_img2);
    pgm_show(OutputFile);

    //GRADIANT

    pgm_t_image *struct_img3;
    struct_img3 = pgm_malloc(512,512);
    pgm_gradient(struct_img3);
    pgm_write(OutputFile, struct_img3);
    pgm_show(OutputFile);

    // call the free function.
    pgm_free(struct_img1);
    pgm_free(struct_img2);
    pgm_free(struct_img3);
    // Appel de la fonction.
        //pgm_show(OutputFile);
/*
//******************************************** IMAGE UNIE PLEINE COULEUR *********************************

    // Allouer dynamiquement une image
    pgm_t_pixel *imageD = pgm_malloc(width, height);
    // Mettre un nom d'image
    char imageDname[] = "image-dynamique";
    
    pgm_solid(imageD, width, height, 0);
    pgm_naivewrite(imageDname, imageD, width, height);

    // On peut le free avant car on sait ou l'image créée sera.
    // On met le nom du fichier conçu en amont.
    pgm_show(imageDname);

    // libérer la mémoire

//******************************************** IMAGE MODE NEGATIF *********************************  

    pgm_negative(imageD, width, height);
    pgm_naivewrite("image-dynamique-negatif", imageD, width, height);

    pgm_show("image-dynamique-negatif");

    // Utiliser l'image de base (et pas l'image unie) pour voir les effets.
    pgm_threshold(vectorPixels, width, height, 150);
    pgm_naivewrite("image-dynamique-seuil", vectorPixels, width, height);

    pgm_show("image-dynamique-seuil");

//******************************************** IMAGE DEGRADE *********************************  

    pgm_gradient(imageD, width, height);
    pgm_naivewrite("image-dynamique-degrade", imageD, width, height);

    pgm_show("image-dynamique-degrade");
*/

    return EXIT_SUCCESS;
}