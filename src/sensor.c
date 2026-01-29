#include<stdlib.h>
#include<stdio.h>
#include "sensor.h"
#include "ventilation.h"

float acquire_sensor_data(){
    
    static float temp_actuelle = 25.0f; 
   
    
    if((rand() % 20) == 0){
        float parasite =80.0f + ((float)(rand() % 31));
        return parasite;
    }

  
   
    if (is_Running()) {
        // FORCE DÉCROISSANTE : On retire 1.5°C à chaque mesure
        
        temp_actuelle -= 1.5f; 
    } else {
        // MONTEE : On ajoute 0.3°C + un petit bruit
        temp_actuelle += 0.3f + ((float)rand() / (float)RAND_MAX * 0.1f);
    }

    
    if (temp_actuelle < 15.0f) temp_actuelle = 15.0f;

    return temp_actuelle;
}

 
