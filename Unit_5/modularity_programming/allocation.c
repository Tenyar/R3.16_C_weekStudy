#include <stdio.h>
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

void pgm_free(pgm_t_image *struct_img){

    free(struct_img->pixels);
    free(struct_img);
}