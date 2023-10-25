#include "led_task_threads.h"
#include "macros.h"
#include "audio.h"
#include "controller.h"
#include "motor.h"

int main() {
    SystemCoreClockUpdate();
	initUART();
	
    osKernelInitialize();
	
	// Set up the threads
	osThreadNew(red_led_thread, NULL, NULL);
    osThreadNew(green_led_thread, NULL, NULL);
    osThreadNew(audioThread, NULL, NULL);
    osThreadNew(controllerThread, NULL, NULL);
	osThreadNew(motorThread, NULL, NULL);

    osKernelStart();

	while (1);
}
