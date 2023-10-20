#include "macros.h"
#include "uart.h"

void controllerThread(void* argument) {
	for (;;) {
		osSemaphoreAcquire(mySem, osWaitForever);

		myDataPacket packet = {
			.leftWheelPwm = data & (MASK(0) | MASK(1) | MASK(2)),
			.rightWheelPwm = (data & (MASK(3) | MASK(4) | MASK(5))) >> 3,
			.isCompleted = data & MASK(7)
		};

		// Send the message to the message queue
		osMessageQueuePut(leftWheelPwmMsg, &packet, NULL, 0);
		osMessageQueuePut(rightWheelPwmMsg, &packet, NULL, 0);
		osMessageQueuePut(isCompletedMsg, &packet, NULL, 0);
	}
}
