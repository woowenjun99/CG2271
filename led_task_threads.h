 #include "macros.h"

/** ======================== GPIO Logic =========================== */

void offLed() {
    /// We write a 1 to the set register to set the bits to 1 to turn them off.
    PTB->PSOR |= MASK(RED_LED_PIN) | MASK(GREEN_LED_PIN);
}

void initGPIO() {
    /// Clock gating logic to PORT B since we will be using it for GPIO.
    SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
    
    /// Set the necessary pins to GPIO.
    PORTB->PCR[RED_LED_PIN] &= ~PORT_PCR_MUX_MASK;
    PORTB->PCR[RED_LED_PIN] |= PORT_PCR_MUX(1);
    PORTB->PCR[GREEN_LED_PIN] &= ~PORT_PCR_MUX_MASK;
    PORTB->PCR[GREEN_LED_PIN] |= PORT_PCR_MUX(1);
    
    /// Set the GPIO to output.
    PTB->PDDR |= MASK(RED_LED_PIN) | MASK(GREEN_LED_PIN);
    
    offLed();
}

void ledControl(int led, int value) {
    if (value) {
        PTB->PCOR |= MASK(led);
    } else {
        PTB->PSOR |= MASK(led);
    }
}

/** ======================== GPIO Logic =========================== */

void red_led_thread(void *argument) {
    initGPIO();
    
    while (1) {
        ledControl(RED_LED_PIN, 0);
        osDelay(5000);
        ledControl(RED_LED_PIN, 1);
        osDelay(5000);
    }
}

void green_led_thread(void *argument) {
    initGPIO();
    
    while (1) {
        ledControl(GREEN_LED_PIN, 0);
        osDelay(5000);
        ledControl(GREEN_LED_PIN, 1);
        osDelay(5000);
    }
}
