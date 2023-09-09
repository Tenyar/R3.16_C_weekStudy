#include <stdio.h>
#include <pgmio.h>
#include "traitement.h"

void pgm_solid(pgm_t_image * struct_img, pgm_t_pixel color){
    AFFICHER_FONCTION(__func__);
    for (size_t i = 0; i < (struct_img->width * struct_img->height); i++)
    {
        struct_img->pixels[i] = color;
    }
    

}

void pgm_negative(pgm_t_image * struct_img){
    AFFICHER_FONCTION(__func__);
    for (size_t i = 0; i < (struct_img->width * struct_img->height); i++)
    {
        int newcolor = UCHAR_MAX - struct_img->pixels[i];
        struct_img->pixels[i] = newcolor;
    }
    

}

void pgm_threshold(pgm_t_image * struct_img, pgm_t_pixel threshold){
    AFFICHER_FONCTION(__func__);
    for (size_t i = 0; i < (struct_img->width * struct_img->height); i++)
    {
      SEUIL2_PIXEL(struct_img->pixels[i], threshold);
    }
}

void pgm_gradient(pgm_t_image * struct_img){
    AFFICHER_FONCTION(__func__);
    for (size_t i = 0; i < (struct_img->width * struct_img->height); i++)
    {
        struct_img->pixels[i] = (i % struct_img->width) / (float) struct_img->width * PGM_PIXEL_MAX;
    }

}