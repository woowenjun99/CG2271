#pragma once

// System
#include "RTE_Components.h"
#include CMSIS_device_header
#include "cmsis_os2.h"
#include "system_MKL25Z4.h"

#define SYSCLK 48000000

// Random stuff
#define RED_LED_PIN   18
#define GREEN_LED_PIN 19
#define MASK(x)       (1 << (x))

// Audio
#define AUDIO_PRESCALAR        256 // x2 because center-aligned
#define AUDIO_PIN              0   // Port B Pin 0
#define AUDIO_VOLUME_DIVIDER   25
#define AUDIO_DELAY(x, on) ((on ? x * 3 : x) / 4)

// UART
#define UART_BAUD_RATE 115200
#define UART_RX_PIN    23     // Port E Pin 23
#define UART2_INT_PRIO 128

// Global variables
osSemaphoreId_t mySem;
