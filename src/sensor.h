#ifndef _SENSOR_H
#define _SENSOR_H



/**
 * @ sensor simule la lecture d'un capteur réel
 * @ return une valeur float aléatoire
 * Renvoie occasionnelement des parasite
 * 
 */
typedef struct 
{
    char *nom;
    float (* lire)();

} Sensor;
 

 float acquire_sensor_data();

 #endif
