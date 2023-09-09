#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <naivepgmio.h>

// retourne l'@ de la zone mémoire allouée pour stocker les pixels.
pgm_t_pixel *pgm_malloc(int width, int height){

    // Pointeur vers les pixel
    pgm_t_pixel * imgDynamic;
    // Allouer de la place pour l'image.
    imgDynamic = malloc ((width * height) * sizeof(pgm_t_pixel));
    // width * height = surface de l'image

    if (imgDynamic == NULL)
    {
        printf("\nOut of memory!\n");
        return NULL;
    }
    else
    {
        return imgDynamic;
    }
}

void pgm_solid(pgm_t_pixel *pixels, int width, int height, pgm_t_pixel color){

    for (int i = 0; i < (width * height); i++)
    {
        pixels[i] = color;
    }
    

}

void pgm_negative(pgm_t_pixel *pixels, int width, int height){

    for (int i = 0; i < (width * height); i++)
    {
        int newcolor = UCHAR_MAX - pixels[i];
        pixels[i] = newcolor;
    }
    

}

void pgm_threshold(pgm_t_pixel *pixels, int width, int height, pgm_t_pixel threshold){

    for (int i = 0; i < (width * height); i++)
    {
        if (pixels[i] < threshold)
        {
            pixels[i] = 0;
        }
        else
        {
            pixels[i] = UCHAR_MAX;
        }
    }
}

void pgm_gradient(pgm_t_pixel *pixels, int width, int height){

    for (int i = 0; i < (width * height); i++)
    {
        pixels[i] = (i % width) / (float) width * PGM_PIXEL_MAX;
    }

}

// fonction permettant d'afficher une de type image pgm.
void pgm_show(char *filename){

    char command[256];
    snprintf(command, sizeof(command), "eog %s", filename);
    system(command);
}

int main(void) {
    
    // Variable nécessaire à l'écriture et la lecture d'une image pgm. 
    char *fileRead = "guadalest.pgm";

    // Variable qui sera le nouveau fichier copié de l'image.
    char *OutputFile = "guadalest_copie.pgm";
    size_t width, height;

    // extrait les informations sur la largeur et la hauteur de l'image, et retourne un pointeur vers un tableau de pixels (représentés par le type).
    pgm_t_pixel *vectorPixels = pgm_naiveread(fileRead, &width, &height);


    // Ecrire la copie de l'image a partir de l'original.
    pgm_naivewrite(OutputFile, vectorPixels, width, height);

    // Appel de la fonction.
        //pgm_show(OutputFile);

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

    free(vectorPixels);
    free(imageD);

    return EXIT_SUCCESS;
}