// Ceci est la garde pré-processeur pour éviter des erreurs de définitions multiples.
#ifndef ALLOCATION_H_  /* convention classique: nom du module en majuscules, suivi de _H_ */
#define ALLOCATION_H_

/* contenu du fichier */
pgm_t_image *pgm_malloc(size_t width, size_t height);
void pgm_free(pgm_t_image *struct_img);

#endif /* MON_MODULE_H_ */