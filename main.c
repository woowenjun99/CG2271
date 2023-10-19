#include "led_task_threads.h"
#include "macros.h"
#include "audio.h"
#include "controller.h"
#include "motor.h"

const osThreadAttr_t threadPriorityHigh = {
	.priority = osPriorityHigh
};

int main() {
    SystemCoreClockUpdate();
		initUART();
	
    osKernelInitialize();
    osThreadNew(red_led_thread, NULL, NULL);
    osThreadNew(green_led_thread, NULL, NULL);
    osThreadNew(audioThread, NULL, NULL);
    osThreadNew(controllerThread, NULL, &threadPriorityHigh);
		osThreadNew(motorThread, NULL, NULL);
    osKernelStart();

	while (1);
}
