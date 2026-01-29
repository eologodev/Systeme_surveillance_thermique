extern "C"{
#include "buffer.h"
#include "sensor.h"
#include "ventilation.h"

}
Sensor capteur ;
Buffer *buffer;

int serial_putchar(char c, FILE* f) {
    return Serial.write(c);
  }

void setup() {
  fdevopen(serial_putchar, NULL);
  // put your setup code here, to run once:
   Serial.begin(115200);
    init_ventilation();

    
    capteur .nom =(char*)"Decteur de chaleur";
    capteur.lire = acquire_sensor_data;
    log_event(capteur.nom , 0);

    size_t size_buffer= 10;
    buffer = create_buffer(size_buffer);

    printf("--- SYSTEME DE SURVEILLANCE PRET ---\n");

    

    Serial.println("--- Systeme  Demarre ---\n");
    Serial.print("Seuil de securite : 35.0 C | Taille du lissage : ");
    Serial.println(size_buffer);


}

void loop() {
  // put your main code here, to run repeatedly:
  
    
    float temperature = capteur.lire();
    if(temperature <80.0f){
      if(buffer_add(buffer , temperature)){

      float moyenne = moy_buffer(buffer);
      
      
      Serial.print("Mesure Brute: ") ; Serial.print(temperature); 
      Serial.print("Lissee: ") ; Serial.println(moyenne); 
                    
          
           manage_ventilation(moyenne);
           
        
           

      }
    
    }
    else {
            // C'est un parasite (entre 70 et 100°C)
            Serial.print("Parasite Température: "); Serial.print(temperature);
            Serial.println("->valeur ignorée");
        

        
    }

    delay(500);
}
