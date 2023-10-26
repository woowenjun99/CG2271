#include "macros.h"
#include "audio.h"
#include "led.h"
#include "motor.h"

int main() {
    SystemCoreClockUpdate();
	initUART();
	
    osKernelInitialize();
	
	// Set up the threads
    osThreadNew(audioThread, NULL, NULL);
    osThreadNew(ledThread, NULL, NULL);
    osThreadNew(motorThread, NULL, NULL);
    osKernelStart();
}
