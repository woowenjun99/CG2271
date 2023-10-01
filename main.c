#define RED_LED 	18
#define GREEN_LED	19
#define MASK(x)		(1 << (x))
#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"
#include "system_MKL25Z4.h"

/** ======================== GPIO Logic =========================== */
void initGPIO(void) {
	/// Clock gating logic to PORT B since we will be using it for GPIO.
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
	
	/// Set the necessary pins to GPIO.
	PORTB->PCR[RED_LED] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[RED_LED] |= PORT_PCR_MUX(1);
	PORTB->PCR[GREEN_LED] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[GREEN_LED] |= PORT_PCR_MUX(1);
	
	/// Set the GPIO to output.
	PTB->PDDR |= MASK(RED_LED) | MASK(GREEN_LED);
}

void offLed(void) {
	/// We write a 1 to the set register to set the bits to 1 to turn them off.
	PTB->PSOR |= MASK(RED_LED) | MASK(GREEN_LED);
}

/**
@param value We set 1 to be turned off and 0 to be turned on
*/
void ledControl(int led, int value) {
	PTB->PDOR = value << led;
}

/** ======================== GPIO Logic =========================== */

void red_led_thread (void *argument) {
  for (;;) {
		ledControl(RED_LED, 0);
		osDelay(1000);
		ledControl(RED_LED, 1);
		osDelay(1000);
	}
}

void green_led_thread (void *argument) {
  for (;;) {
		ledControl(GREEN_LED, 0);
		osDelay(1000);
		ledControl(GREEN_LED, 1);
		osDelay(1000);
	}
}
 
int main (void) {
  SystemCoreClockUpdate();
	initGPIO();
	offLed();
	
  osKernelInitialize();                 // Initialize CMSIS-RTOS
  osThreadNew(red_led_thread, NULL, NULL);    // Create application main thread
	osThreadNew(green_led_thread, NULL, NULL);    // Create application main thread
  osKernelStart();                      // Start thread execution
  for (;;) {}
}
