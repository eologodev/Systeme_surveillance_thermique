#include <Arduino.h>

// Inclusion sécurisée des fichiers C
extern "C" {
  #include "buffer.h"
  
}

#include "ventilation.h"
#include "sensor.h"

Buffer* buffer ;

void setup() {
  // 1. Initialisation du port série (Vitesse 115200)
  Serial.begin(115200);
  
  // Petite pause pour laisser le temps au moniteur de se connecter
  delay(1000); 
  
  pinMode(14, INPUT_PULLUP);

  // 2. Initialisation du Buffer
  Serial.print("Initialisation du buffer... ");
  size_t taille_buffer = 10;
  buffer = create_buffer(taille_buffer);
  
  if (buffer == NULL) {
    Serial.println("ECHEC ! (Erreur memoire)");
    while(1); 
  }
  
  Serial.print("Initialisation du capteur DHT... ");
  init_sensor();
  Serial.println("OK.");

  
  Serial.print("Initialisation ventilation... ");
  init_ventilation();
  Serial.println("OK.");

  Serial.println("--- SYSTEME PRET ---");
}

void loop() {
  Serial.println("\n--- Nouvelle lecture ---");
  
  // Lecture des données
  float temp = acquire_sensor_data();
  if(temp <100.0 ){
 if( buffer_add(buffer , temp)){
  Serial.println(buffer->cpt);
  float moy = moy_buffer(buffer);
  float var = calcul_variation(buffer);

  Serial.print("var"); Serial.println(var);
  Serial.print("moy") ;Serial.println(moy);

 
  // Affichage pour vérifier
  Serial.print("Temp: "); Serial.print(temp); 

  


  manage_ventilation(moy, var);
 }
} else{
  Serial.println("parasite détecter");
}
  delay(2000); // Attendre 2 secondes avant la prochaine boucle
}