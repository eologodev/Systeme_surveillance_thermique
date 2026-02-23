#include<stdlib.h>
#include<stdio.h>
#include "sensor.h"
#include "ventilation.h"
#include <DHT.h>
#include <time.h>
#define pin_branch  14
#define dht_type DHT22

DHT dht(pin_branch , dht_type);

void init_sensor(){
  dht.begin(); 

}

float acquire_sensor_data(){
  // on stock nos donnée dans une variable récupérer avec DHTT22(GPIO14)*


  float temp = dht.readTemperature();
  if(isnan(temp)){
   Serial.println("Aucune donnée renvoyer ");
  
  }
  return temp;

}

 