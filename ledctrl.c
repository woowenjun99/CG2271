#include "LEDctrl.h"

uint8_t greenPins[] = {8,9,13,5,0,2,3,1,18,20}; 
//Port C 8,9 ; Port A 13 ; Port D 5,0,2,3,1 ; Port E 18,20
uint8_t pinsA[] = {1,2,13};
uint8_t pinsC[] = {8,9};
uint8_t pinsD[] = {5,0,2,3,1};
uint8_t pinsE[] = {18,20};


void initLEDModules() {
  InitGPIOAll(PORTA, pinsA, NUM_LED_A);
  InitGPIOAll(PORTC, pinsC, NUM_LED_C);
  InitGPIOAll(PORTD, pinsD, NUM_LED_D);
	InitGPIOAll(PORTE, pinsE, NUM_LED_E);
}

void offRedModule() {   //Port A 1,2
  setPin(PORTA, pinsA[0], LOW);
	setPin(PORTA, pinsA[1], LOW);
}

void offGreenModule() {
  uint8_t i = 0;
  for (; i < 2; ++i)
    setPin(PORTC, greenPins[i], LOW);
	for (; i < 3; ++i)
    setPin(PORTA, greenPins[i], LOW);
	for (; i < 5; ++i)
    setPin(PORTD, greenPins[i], LOW);
  for (; i < 10; ++i)
    setPin(PORTE, greenPins[i], LOW);
}

void offLEDModules() {
  offRedModule();
  offGreenModule();
}

void onOffLED(PORT_Type *port, uint8_t pin) {
  setPin(port, pin, HIGH);
  osDelay(DELAY_LED_RUN);
  setPin(port, pin, LOW);
}

void runningLED() {
  offGreenModule();
  uint8_t i = 0;
  for (; i < 2; ++i)
    onOffLED(PORTC, greenPins[i]);
	for (; i < 3; ++i)
    onOffLED(PORTA, greenPins[i]);
	for (; i < 5; ++i)
    onOffLED(PORTD, greenPins[i]);
  
  for (; i < 10; ++i)
    onOffLED(PORTE, greenPins[i]);
}

void allLitLED() {
  uint8_t i = 0;
  for (; i < 2; ++i)
    setPin(PORTC, greenPins[i], HIGH);
	for (; i < 3; ++i)
    setPin(PORTA, greenPins[i], HIGH);
	for (; i < 5; ++i)
    setPin(PORTD, greenPins[i], HIGH);
  for (; i < 10; ++i)
    setPin(PORTE, greenPins[i], HIGH);
}

void flash2GreenLED() {
  for (uint8_t i = 0; i < 2; ++i)
    flashGreenLEDDelay(i);
}

void flashGreenLEDDelay(uint8_t in) {
  uint8_t i = in;  
  for (; i < 2; )
    setPin(PORTC, greenPins[i], HIGH);
	for (; i < 3; )
    setPin(PORTA, greenPins[i], HIGH);
	for (; i < 5; )
    setPin(PORTD, greenPins[i], HIGH);
  for (; i < 10;)
    setPin(PORTE, greenPins[i], HIGH);
  delay2(0x4FFF);
  

  i = in;
  for (; i < 2; )
    setPin(PORTC, greenPins[i], LOW);
	for (; i < 3; )
    setPin(PORTA, greenPins[i], LOW);
	for (; i < 5; )
    setPin(PORTD, greenPins[i], LOW);
  for (; i < 10;)
    setPin(PORTE, greenPins[i], LOW);
  
  delay2(0x4FFF);
}

void flashGreenLED(uint8_t in) {
  uint8_t i = in;  
  for (; i < 2; )
    setPin(PORTC, greenPins[i], HIGH);
	for (; i < 3; )
    setPin(PORTA, greenPins[i], HIGH);
	for (; i < 5; )
    setPin(PORTD, greenPins[i], HIGH);
  for (; i < 10;)
    setPin(PORTE, greenPins[i], HIGH);
  osDelay(DELAY_LED_FLASH);
  

  i = in;
  for (; i < 2; )
    setPin(PORTC, greenPins[i], LOW);
	for (; i < 3; )
    setPin(PORTA, greenPins[i], LOW);
	for (; i < 5; )
    setPin(PORTD, greenPins[i], LOW);
  for (; i < 10;)
    setPin(PORTE, greenPins[i], LOW);
  
  osDelay(DELAY_LED_FLASH);
}

void flashRedLED_1() {
  setPin(PORTC, 1, HIGH);
  osDelay(DELAY_LED_1HZ);
  setPin(PORTC, 1, LOW);
  osDelay(DELAY_LED_1HZ);
}

void flashRedLED_2() {
  setPin(PORTC, 2, HIGH);
  osDelay(DELAY_LED_2HZ);
  setPin(PORTC, 2, LOW);
  osDelay(DELAY_LED_2HZ);
}