#include <stdio.h>
#include <Arduino.h> 
#include "ventilation.h"

int etat_ventilateur = ETAT_OFF;


void init_ventilation() {
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);
    etat_ventilateur = ETAT_OFF;
    printf("[SYSTEME] Initialisation Ventilation OK (Pin 13)\n");
}

bool is_Running() {
    return (etat_ventilateur == ETAT_ON);
}

void log_event(const char* message, float value) {
    printf("[LOG] %s : %.2f\n", message, value);
}

void manage_ventilation(float avg) {

  char buffer_texte[10]; // Pour stocker le nombre converti en texte
   
    // On transforme le float en texte
    dtostrf(avg, 4, 2, buffer_texte);
    // Condition d'allumage
    if (avg > SEUIL_DANGER  && etat_ventilateur == ETAT_OFF) {
        etat_ventilateur = ETAT_ON;
        digitalWrite(13, HIGH); // ALLUME LA LED
       
        printf(">>> ALERTE : VENTILATION ALLUMEE ! (Moy: %s)\n", buffer_texte);
        
        
    } 
    // Condition d'arrêt (Hystérésis de 5 degrés pour éviter les clignotements)
    else if (avg <= (SEUIL_DANGER - 5.0f) && etat_ventilateur == ETAT_ON) {
        etat_ventilateur = ETAT_OFF;
        digitalWrite(13, LOW); // ETEINT LA LED
       
        printf(">>> INFO : VENTILATION ETEINTE (Moy: %s)\n", buffer_texte);
       
        
    }
}
