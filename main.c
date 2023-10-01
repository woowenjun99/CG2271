#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"
#include "led_task_threads.h"
 
int main (void) {
  SystemCoreClockUpdate();
	initGPIO();
	offLed();
	
  osKernelInitialize();                 // Initialize CMSIS-RTOS
  osThreadNew(red_led_thread, NULL, NULL);    // Create application main thread
	osThreadNew(green_led_thread, NULL, NULL);    // Create application main thread
  osKernelStart();                      // Start thread execution
  for (;;) {}
}
