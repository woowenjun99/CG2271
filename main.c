#include "led_task_threads.h"
#include "macros.h"
#include "uart.h"

int main (void) {
  SystemCoreClockUpdate();
	initUART();
	initGPIO();

	for (;;) {
		offLed();
		switch(data) {
			case 0:
				offLed();
				break;
			case 1:
				ledControl(RED_LED, 1);
				break;
			default:
				ledControl(GREEN_LED, 1);
		}
	}
}
