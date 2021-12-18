#include <Arduino.h>
#include <WiFi.h>



//------------------------------- Local Library Include Start ------------------------------------//

#include "web_page.hpp"
#include "lamp_drive.hpp"

//-------------------------------- Local Library Include End -------------------------------------//



//--------------------------------- Defination Macro Start ---------------------------------------//

#define SERIAL_BAUD   115200  // Console baud rate (use for debug)

#define WIFI_AP_SSID  "HELLO_NIXIE"
#define WIFI_AP_PASS  "Nixie01!"

//--------------------------------- Defination Macro END------------------------------------------//



//--------------------------------- Global Variable Start ----------------------------------------//

TaskHandle_t taskUpdateLamp_handler;

//--------------------------------- Global Variable End ------------------------------------------//



//--------------------------------- Function Prototype Start -------------------------------------//

uint8_t peripheral_init(void);

//--------------------------------- Function Prototype End ---------------------------------------//



void setup() {

  // TODO: To Complete INIT PERIPHERAL
  peripheral_init();

  // TODO: LOAD PARM from internal memory

  // TODO: WEB SERVER INIT
  webserver_init();

  // TODO: OTHER TASK CREATE

  // TODO: To complete "TaskUpdateLamp"
  xTaskCreatePinnedToCore(
                  taskUpdateLamp,           /* Task function. */
                  "TaskUpdateLamp",         /* name of task. */
                  10000,                    /* Stack size of task */
                  NULL,                     /* parameter of the task */
                  1,                        /* priority of the task */
                  &taskUpdateLamp_handler,  /* Task handle to keep track of created task */
                  1);                       /* pin task to core 0 */          
/AA WebDev//
}



void loop() {
  taskYIELD();  //NOP
}



// FUNCTION:    peripheral_init
// DESCRIPTION: 
//              Init ALL Peripheral, UART, I2C, WIFI,
// PARAM:       NO ARGUMENT
// RETURN:      UINT8, 1 = Complete Initial
uint8_t peripheral_init(void) {

  // UART INIT
  Serial.begin(SERIAL_BAUD);

  // TODO: PWM, I2C, WIFI (AP, STA)

  return 1;

}

// FUNCTION:    wifi_init
// DESCRIPTION: 
//              Config WIFI; AP and STA
// PARAM:       NO ARGUMENT
// RETURN:      UINT8, 1 = Complete Initial
uint8_t wifi_init(){

  // Config WiFi as AP and STA mode
  WiFi.mode(WIFI_MODE_APSTA);

  // Config AP wifi
  WiFi.softAP(WIFI_AP_SSID, WIFI_AP_PASS);

  // TODO: STA config
  // Ex. USE string arg; WiFi.begin(ssid.c_str(),pass.c_str());

  return 1;
}
