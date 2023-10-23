#ifndef GPIO_H
#define GPIO_H

#include "MKL25Z4.h"                    // Device header
#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"

#define MASK(x) (1 << (x))

extern osSemaphoreId_t brainSem;
extern osSemaphoreId_t musicSem;
extern osSemaphoreId_t moveSem;

uint32_t getMaskPort(PORT_Type *port);

/* Delay Function */
void delay(volatile uint32_t nof);

void delay2(volatile uint32_t nof);



typedef enum {LOW, HIGH} value_t;

void initGPIOPort(PORT_Type *port, uint8_t pin);

GPIO_Type* getGPIO(PORT_Type* port);

void InitGPIOAll(PORT_Type *port, uint8_t pins[], uint8_t numPins);

void setPin(PORT_Type *port, uint8_t pin, value_t value);

#endif

led_task_threads.h

 #include "macros.h"

/** ======================== GPIO Logic =========================== */
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
}

void offLed() {
    /// We write a 1 to the set register to set the bits to 1 to turn them off.
    PTB->PSOR |= MASK(RED_LED_PIN) | MASK(GREEN_LED_PIN);
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
        osDelay(1000);
        ledControl(RED_LED_PIN, 1);
        osDelay(1000);
    }
}

void green_led_thread(void *argument) {
    initGPIO();
    
    while (1) {
        ledControl(GREEN_LED_PIN, 0);
        osDelay(1000);
        ledControl(GREEN_LED_PIN, 1);
        osDelay(1000);
    }
}