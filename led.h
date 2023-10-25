#include "macros.h"

void initGPIO() {
    SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
    SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
    
    for (int i = 0; i < 8; i++) {
        RUNNING_LED_PORTS[i]->PCR[RUNNING_LED_PINS[i]] &= ~PORT_PCR_MUX_MASK;
        RUNNING_LED_PORTS[i]->PCR[RUNNING_LED_PINS[i]] |= PORT_PCR_MUX(1);
        RUNNING_LED_GPIOS[i]->PDDR |= MASK(RUNNING_LED_PINS[i]);
    }
    
    FIXED_LED_PORT->PCR[FIXED_LED_PIN] &= ~PORT_PCR_MUX_MASK;
    FIXED_LED_PORT->PCR[FIXED_LED_PIN] |= PORT_PCR_MUX(1);
    FIXED_LED_GPIO->PDDR |= MASK(FIXED_LED_PIN);
}

 void ledThread(void* argument) {
     initGPIO();
     uint8_t ledPtr = 0;
     
     while (1) {
         FIXED_LED_GPIO->PTOR |= MASK(FIXED_LED_PIN);
         if (leftWheelDutyCycle || rightWheelDutyCycle) {
             for (int i = 0; i < 8; i++) {
                 RUNNING_LED_GPIOS[i]->PCOR |= MASK(RUNNING_LED_PINS[i]);
             }
             RUNNING_LED_GPIOS[ledPtr]->PSOR |= MASK(RUNNING_LED_PINS[ledPtr]);
             ledPtr = ledPtr == 7 ? 0 : ledPtr + 1;
             osDelay(5000);
         } else {
             for (int i = 0; i < 8; i++) {
                 RUNNING_LED_GPIOS[i]->PSOR |= MASK(RUNNING_LED_PINS[i]);
             }
             osDelay(2500);
         }
     }
 }
