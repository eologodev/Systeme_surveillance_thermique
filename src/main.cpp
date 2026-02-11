#include <Arduino.h>
extern "C"{
  #include "buffer.h"
#include "sensor.h"
#include "ventilation.h"

}

// put function declarations here:
//int myFunction(int, int);
Buffer *buffer;
Sensor capteur;
unsigned long dernierUpdate = 0;
bool presence =false;

void setup() {
  // put your setup code here, to run once:
 // int result = myFunction(2, 3);

 Serial.begin(115200);
 delay(2000);
  size_t size =10;
  buffer= create_buffer(size);
  capteur.lire = acquire_sensor_data ;
  init_ventilation();
  Serial.println("Demarrage de la simulation");



}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("--- Tick ---"); // Message simple pour tester
    Serial.flush(); // Force l'envoi vers le terminal
  if (millis() -dernierUpdate >=1000){
   
    dernierUpdate = millis();

    long secondes = millis() / 1000;
    
    
    if ((secondes / 10) % 2 == 0) {
      presence = true;
    } else {
      presence = false;
    }

  

  float temperature = capteur.lire();
  if(temperature > 80){
      Serial.print("->Alerte Parasite :"); Serial.println(temperature);

    }else{
       if(buffer_add(buffer , temperature)){
      float moy = moy_buffer(buffer);
      float variation = calcul_variation(buffer);

      manage_ventilation(moy , variation , presence);
      Serial.print("Température |") ; Serial.println(temperature);
      Serial.print("Lissage |") ; Serial.println(variation);
      Serial.print("Variation de la température |") ; Serial.println(variation);
      
     }

    }
 

}
}
// put function definitions here:
/*int myFunction(int x, int y) {
  return x + y;
}*/