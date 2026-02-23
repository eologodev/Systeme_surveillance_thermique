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
  
   
    float somme =0.0;
    if (buffer->cpt==0) return 0;
    for (int i =0 ; i < buffer->cpt ; i++){
        
        somme = somme + buffer->tab[i];

    }
    float moy = somme /buffer->cpt;
    return moy;
}

void destroy_buffer(Buffer *buffer){

    if(buffer){
        free(buffer->tab);
        free (buffer);
    }
}

float calcul_variation(Buffer *buffer){
   
    
    if(!buffer || buffer->cpt <=1) return 0.0;
    
    int i ,j;
    i = buffer->write_place-1;
    if (i<0){
      i=(int)buffer->size-1;
      j =0;
    }else{
      
      j = i-1;
      if(j<0){
        j = (int)buffer->size-1;

      }
    }
    
      float temp_actuelle = buffer->tab[i]; 
      float temp_ancienne = buffer->tab[j];

       float  var = temp_actuelle- temp_ancienne;
    
       return var;
      

    }




   