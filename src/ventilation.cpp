#include <stdio.h>
#include <Arduino.h> 
#include "ventilation.h"
#include <ESP32Servo.h>
#define PIN 12

Servo ventilation;
int position_angle = 0;


void init_ventilation() {
    // allocation d'un timer pour éviter les conflit avec le wifi
    ESP32PWM::allocateTimer(2);
   ventilation.setPeriodHertz(50);
   ventilation.attach(PIN ,300 , 2400);
    printf("[SYSTEME] Initialisation Ventilation \n");
    ventilation.write(0);
}

void is_Running(int angle) {
    if(angle <0) angle =0;
    if (angle >180) angle=180;
   
    ventilation.write(angle);
    position_angle = angle;
    
    
}

void log_event(const char* message, float value) {
    printf("[LOG] %s : %.2f\n", message, value);
}

void manage_ventilation(float avg , float variation ) {

  
     if(variation>0.10){
       
       Serial.println("ALERTE INCENDIE");
        
        is_Running(180);
        
        return ;
        
    } 
    // Condition d'allumage
    if (avg > SEUIL_DANGER ) {
      is_Running(180);
        
       Serial.print(" INFO : VENTILATION ALLUME SEUIL_DANGER (MOY : "); Serial.println(avg); Serial.println(")");
    } else if(avg> SEUIL_CONFORT ){
        
        int angle_voulu = map((int)(avg * 10), (int)(SEUIL_CONFORT * 10), (int)(SEUIL_DANGER * 10), 0, 180);

        is_Running(angle_voulu);
        Serial.print(" INFO : VENTILATION ALLUME SEUIL_CONFORT (MOY : "); Serial.println(avg); Serial.println(")");

    }
    // Condition d'arrêt (Hystérésis de 5 degrés pour éviter les clignotements)
    else if (avg <= (SEUIL_DANGER - 5.0f)) {
        if(position_angle >0){
            is_Running(0);
        } 
        Serial.print(" INFO : VENTILATION ETEINTE (MOY : "); Serial.print(avg); Serial.println(")");
        
    }

   
}