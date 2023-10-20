#include "led_task_threads.h"
#include "macros.h"
#include "audio.h"
#include "controller.h"
#include "motor.h"

int main() {
    SystemCoreClockUpdate();
		initUART();
	
    osKernelInitialize();

		// Create message queues
		leftWheelPwmMsg = osMessageQueueNew(MSG_COUNT, sizeof(myDataPacket), NULL);
		rightWheelPwmMsg = osMessageQueueNew(MSG_COUNT, sizeof(myDataPacket), NULL);
		isCompletedMsg = osMessageQueueNew(MSG_COUNT, sizeof(myDataPacket), NULL);

		// Create semaphores
		mySem = osSemaphoreNew(1, 0, NULL);
	
		// Set up the threads
		osThreadNew(red_led_thread, NULL, NULL);
    osThreadNew(green_led_thread, NULL, NULL);
    osThreadNew(audioThread, NULL, NULL);
    osThreadNew(controllerThread, NULL, NULL);
		osThreadNew(motorThread, NULL, NULL);

    osKernelStart();

	while (1);
}
