#include "led_task_threads.h"
#include "macros.h"
#include "tAudio.h"
#include "tBrain.h"

const osThreadAttr_t thread_attr = {
	.priority = osPriorityHigh
};

int main (void) {
    SystemCoreClockUpdate();
    initUART();
    initGPIO();
    initPWM();

    osKernelInitialize();
		mySem = osSemaphoreNew(1, 1, NULL);
    osThreadNew(red_led_thread, NULL, NULL);
    osThreadNew(green_led_thread, NULL, NULL);
    osThreadNew(audioThread, NULL, NULL);
		osThreadNew(tBrain, NULL, &thread_attr);
    osKernelStart();

	while (1);
}
