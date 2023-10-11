#include "led_task_threads.h"
#include "macros.h"
#include "uart.h"
#include "tAudio.h"

int main (void) {
    SystemCoreClockUpdate();
    initUART();
    initGPIO();
    initPWM();
    
    osKernelInitialize();
    osThreadNew(red_led_thread, NULL, NULL);
    osThreadNew(green_led_thread, NULL, NULL);
    osThreadNew(audioThread, NULL, NULL);
    osKernelStart();
    while (1);
}
