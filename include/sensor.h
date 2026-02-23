
#ifndef _SENSOR_H
#define _SENSOR_H
#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif



/**
 * initialise et Retourne la température lue via le capture(GPIO , BIBLIOTHEQUE DHT)
 * 
 */

 //
 void init_sensor();

 float acquire_sensor_data();

#ifdef __cplusplus
  }
#endif


 #endif