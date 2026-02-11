#include<stdlib.h>
#include<stdio.h>
#include "sensor.h"
#include "ventilation.h"

float acquire_sensor_data(){
    // On utilise STATIC : la variable n'est créée qu'UNE SEULE FOIS.
    // Elle garde sa valeur entre deux appels de la fonction.
    static float temp_actuelle = 25.0f; 
   
    // 1. Gestion du parasite (Inchangé, c'est très bien)
    if((rand() % 20) == 0){
        float parasite =80.0f + ((float)(rand() % 31));
        return parasite;
    }

    // 2. Évolution progressive
   
    if (is_Running()) {
        // FORCE DÉCROISSANTE : On retire 0.5°C à chaque mesure
        // Pas de rand() ici pour que ce soit fluide et constant
        temp_actuelle -= 1.5f; 
    } else {
        // MONTEE : On ajoute 0.3°C + un petit bruit
        temp_actuelle += 0.3f + ((float)rand() / (float)RAND_MAX * 0.1f);
    }

    // 3. Sécurité basse (pour éviter le gel !)
    if (temp_actuelle < 15.0f) temp_actuelle = 15.0f;

    return temp_actuelle;
}

 