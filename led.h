#include "macros.h"

void initGPIO() {
    SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
    SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
    
    for (int i = 0; i < 8; i++) {
        RUNNING_LED_PORTS[i]->PCR[RUNNING_LED_PINS[i]] &= ~PORT_PCR_MUX_MASK;
        RUNNING_LED_PORTS[i]->PCR[RUNNING_LED_PINS[i]] |= PORT_PCR_MUX(1);
        RUNNING_LED_GPIOS[i]->PDDR |= MASK(RUNNING_LED_PINS[i]);
    }
}

 void ledThread(void* argument) {
     
 }
