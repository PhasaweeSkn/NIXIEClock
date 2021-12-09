#ifndef __LAMP_DRIVE_H_INCLUDED
#define __LAMP_DRIVE_H_INCLUDED

#include <Arduino.h>

void taskUpdateLamp(void * pvParameters);
uint8_t updateLamp(void);

#endif