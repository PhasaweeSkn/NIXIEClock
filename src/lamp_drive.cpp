#include "lamp_drive.hpp"

void taskUpdateLamp(void * pvParameters){

    while (true) {
        // TODO: TASK PROCESS


        vTaskDelay(20 / portTICK_PERIOD_MS);    //Do task every 20 ms
    }

    vTaskDelete(NULL);  // Kill task
}


uint8_t updateLamp(void){
    return 0;

}
