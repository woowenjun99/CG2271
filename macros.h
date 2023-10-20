#pragma once

// System
#include "RTE_Components.h"
#include CMSIS_device_header
#include "cmsis_os2.h"
#include "system_MKL25Z4.h"
#include "stdlib.h"

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

// MOTOR
#define LEFT_MOTOR_FORWARD_PIN 1 // Port C Pin 1
#define RIGHT_MOTOR_FORWARD_PIN 2 //Port C Pin 2
#define LEFT_MOTOR_REVERSE_PIN 3 // Port C Pin 3
#define RIGHT_MOTOR_REVERSE_PIN 4 //Port C Pin 4
#define MOD_VALUE 7500 //period of PWM
#define HIGH_VALUE 7500 //lower this value to lower max speed
// Global variables
osSemaphoreId_t mySem;

// Message Queue
#define MSG_COUNT 1

typedef struct {
	uint8_t isCompleted;
	uint8_t leftWheelPwm;
	uint8_t rightWheelPwm;
} myDataPacket;

osMessageQueueId_t isCompletedMsg;
osMessageQueueId_t leftWheelPwmMsg;
osMessageQueueId_t rightWheelPwmMsg;
