#include<stdlib.h>
#include<stdio.h>
#include "buffer.h"
#include<stdbool.h>

Buffer *create_buffer(size_t size){

   Buffer * buffer = malloc(sizeof(Buffer));
   if (!buffer) return NULL;
   
   
   buffer->cpt =0;
   buffer->size = size;
   buffer ->write_place =0;

   buffer ->tab = malloc(sizeof(float) * size);
   if (!buffer->tab ){
    free(buffer);
    return NULL;
   }

   return buffer;

}

bool buffer_add(Buffer * buffer , float temperature){

    if(!buffer) return false;
    int lenght = (int)buffer->size - 1;

    buffer->tab[buffer->write_place] =temperature;
      buffer->write_place ++;
      if(buffer->write_place >lenght){
        buffer->write_place =0;

      } 

    if(buffer->cpt<=lenght){

      
      buffer->cpt ++;

     
    }
     return true;
}

float moy_buffer(Buffer *buffer){

    int i ;
    float somme =0.0;
    if (buffer->cpt==0) return 0;
    for (i =0 ; i <(int) buffer->cpt ; i++){
        
        somme = somme + buffer->tab[i];

    }
    float moy = somme /(int)buffer->cpt;
    return moy;
}

void destroy_buffer(Buffer *buffer){

    if(buffer){
        free(buffer->tab);
        free (buffer);
    }
}


   
