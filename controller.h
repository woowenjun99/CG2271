#include "macros.h"
#include "uart.h"

volatile uint8_t leftWheelPWM = 0;
volatile uint8_t rightWheelPWM = 0;
volatile uint8_t isCompleted = 0;

void _parseIsCompleted() {
	isCompleted = data & MASK(3);
}

void controllerThread(void* argument) {
	for (;;) {
		_parseIsCompleted(); 
		leftWheelPWM = data & (MASK(0) | MASK(1) | MASK(2));
		rightWheelPWM = (data & (MASK(3) | MASK(4) | MASK(5))) >> 3;
	}
}
