#include "led_task_threads.h"
#include "macros.h"
#include "audio.h"
#include "controller.h"

const osThreadAttr_t threadPriorityHigh = {
	.priority = osPriorityHigh
};

int main() {
    SystemCoreClockUpdate();

    osKernelInitialize();
    mySem = osSemaphoreNew(1, 1, NULL);
    osThreadNew(red_led_thread, NULL, NULL);
    osThreadNew(green_led_thread, NULL, NULL);
    osThreadNew(audioThread, NULL, NULL);
    osThreadNew(controllerThread, NULL, &threadPriorityHigh);
    osKernelStart();

	while (1);
}
