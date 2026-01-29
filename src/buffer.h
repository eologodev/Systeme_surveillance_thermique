#ifndef _BUFFER_H
#define _BUFFER_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
int cpt ; // compteur d'élement actuel dans le buffer
float * tab; // tableau pour socker les températures
size_t size; //la taille du buffer*
int write_place ; // position d'écriture dans le buffer
} Buffer;

Buffer *create_buffer(size_t size); 
bool buffer_add(Buffer * buffer , float temperature);
float moy_buffer(Buffer *buffer);
void destroy_buffer(Buffer *buffer);


#endif
