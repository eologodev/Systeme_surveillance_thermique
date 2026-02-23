#ifndef _VENTILATION_H
#define _VENTILATION_H
#define SEUIL_DANGER 35.0f
#define SEUIL_CONFORT 25.0f

#ifdef __cplusplus
extern "C" {
#endif





void init_ventilation();
void is_Running(int etat);
void manage_ventilation(float avg , float variation) ;
void log_event(const char* message, float value);
#ifdef __cplusplus
 }
#endif

#endif