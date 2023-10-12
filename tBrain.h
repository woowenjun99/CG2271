#include "macros.h"
#include "uart.h"

enum Direction {
	FORWARD,
	LEFT,
	REVERSE,
	RIGHT,
	STOP,
};

volatile enum Direction currentDirection = STOP;
volatile uint8_t isCompleted = 0;

/**
Using the first 2 bits of the data that we received via UART,
we determine the direction that we are moving.
*/
void _parseDirection() {
	uint8_t direction = data & (MASK(0) | MASK(1) | MASK(2));

	switch (direction) {
		case 0:
			currentDirection = STOP;
			break;
		case 1:
			currentDirection = FORWARD;
			break;
		case 2:
			currentDirection = LEFT;
			break;
		case 3:
			currentDirection = REVERSE;
			break;
		default:
			currentDirection = RIGHT;
	}
}

void _parseIsCompleted() {
	isCompleted = data & MASK(3);
}

void tBrain(void* argument) {
	for (;;) {
		osSemaphoreAcquire(mySem, osWaitForever);
		_parseIsCompleted(); 
		_parseDirection();
	}
}
