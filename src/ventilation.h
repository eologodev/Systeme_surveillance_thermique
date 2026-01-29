#ifndef _VENTILATION_H
#define _VENTILATION_H
#define SEUIL_DANGER 35.0f
#define ETAT_OFF 0
#define ETAT_ON 1
#include <stdbool.h>



void init_ventilation();
bool is_Running();
void manage_ventilation(float avg);
void log_event(const char* message, float value);
#endif
