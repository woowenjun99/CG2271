#include "macros.h"

PORT_Type* RUNNING_LED_PORTS[] = {PORTB, PORTB, PORTB, PORTB, PORTE, PORTE, PORTE, PORTE};
GPIO_Type* RUNNING_LED_GPIOS[] = {PTB, PTB, PTB, PTB, PTE, PTE, PTE, PTE};
const uint8_t RUNNING_LED_PINS[] = {8, 9, 10, 11, 2, 3, 4, 5};

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
