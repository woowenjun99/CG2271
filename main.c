#include "led_task_threads.h"
#include "tAudio.h"
 
int main (void) {
  SystemCoreClockUpdate();
	initGPIO();
	offLed();
	initPWM();
	
  osKernelInitialize();
  osThreadNew(red_led_thread, NULL, NULL);
	osThreadNew(green_led_thread, NULL, NULL);
  osKernelStart();
  for (;;) {}
}
