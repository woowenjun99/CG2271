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
#define AUDIO_PRESCALAR      64 // x2 because center-aligned
#define AUDIO_PIN            0  // Port B Pin 0
#define AUDIO_VOLUME_DIVIDER (100 * 40)

#define NOTE_REST 65535

#define NOTE_C3   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 130.81)
#define NOTE_CS3  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 138.59)
#define NOTE_D3   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 146.83)
#define NOTE_DS3  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 155.56)
#define NOTE_E3   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 164.81)
#define NOTE_F3   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 174.61)
#define NOTE_FS3  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 185)
#define NOTE_G3   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 196)
#define NOTE_GS3  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 207.65)
#define NOTE_A3   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 220)
#define NOTE_AS3  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 233.08)
#define NOTE_B3   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 246.94)

#define NOTE_C4   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 261.63)
#define NOTE_CS4  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 277.18)
#define NOTE_D4   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 293.66)
#define NOTE_DS4  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 311.13)
#define NOTE_E4   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 329.63)
#define NOTE_F4   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 349.23)
#define NOTE_FS4  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 369.99)
#define NOTE_G4   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 392)
#define NOTE_GS4  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 415.3)
#define NOTE_A4   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 440)
#define NOTE_AS4  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 466.16)
#define NOTE_B4   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 493.88)

#define NOTE_C5   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 523.25)
#define NOTE_CS5  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 554.37)
#define NOTE_D5   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 587.33)
#define NOTE_DS5  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 622.25)
#define NOTE_E5   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 659.25)
#define NOTE_F5   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 698.46)
#define NOTE_FS5  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 739.99)
#define NOTE_G5   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 783.99)
#define NOTE_GS5  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 830.61)
#define NOTE_A5   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 880)
#define NOTE_AS5  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 932.33)
#define NOTE_B5   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 987.77)

#define NOTE_C6   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 1046.5)
#define NOTE_CS6  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 1108.73)
#define NOTE_D6   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 1174.66)
#define NOTE_DS6  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 1244.51)
#define NOTE_E6   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 1318.51)
#define NOTE_F6   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 1396.91)
#define NOTE_FS6  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 1479.98)
#define NOTE_G6   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 1567.98)
#define NOTE_GS6  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 1661.22)
#define NOTE_A6   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 1760)
#define NOTE_AS6  (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 1864.66)
#define NOTE_B6   (uint16_t) (SYSCLK / AUDIO_PRESCALAR / 1975.53)

const uint16_t NOTE_VALUES_1[] = {NOTE_E5, NOTE_E5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_C6, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_E5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_B5, NOTE_G5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_C6, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_E5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_B5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_REST, NOTE_E5, NOTE_E5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_C6, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_E5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_B5, NOTE_E5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_C6, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_E5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_B5, NOTE_E5, NOTE_E5, NOTE_B5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_D6, NOTE_E6, NOTE_B5, NOTE_E6, NOTE_D6, NOTE_E6, NOTE_D6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_FS6, NOTE_E6, NOTE_D6, NOTE_B5, NOTE_B5, NOTE_D6, NOTE_E6, NOTE_E6, NOTE_FS6, NOTE_E6, NOTE_D6, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_C6, NOTE_B5, NOTE_E6, NOTE_E6, NOTE_FS6, NOTE_E6, NOTE_D6, NOTE_B5, NOTE_B5, NOTE_D6, NOTE_E6, NOTE_E6, NOTE_FS6, NOTE_E6, NOTE_D6, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_E6, NOTE_B5, NOTE_B5, NOTE_E6, NOTE_E6, NOTE_FS6, NOTE_E6, NOTE_D6, NOTE_B5, NOTE_B5, NOTE_D6, NOTE_E6, NOTE_E6, NOTE_FS6, NOTE_E6, NOTE_D6, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_C6, NOTE_B5, NOTE_E6, NOTE_E6, NOTE_FS6, NOTE_E6, NOTE_D6, NOTE_B5, NOTE_B5, NOTE_D6, NOTE_E6, NOTE_E6, NOTE_FS6, NOTE_E6, NOTE_D6, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_E6, NOTE_E6, NOTE_REST};
const uint16_t NOTE_DELAYS_1[] = {1417, 1429, 2857, 2857, 2857, 1429, 5714, 1429, 2857, 2857, 2857, 1429, 1429, 2857, 2857, 2857, 5714, 1429, 1429, 2857, 2857, 2857, 1429, 4286, 2857, 2857, 2857, 2857, 1429, 1429, 2857, 2857, 2857, 5714, 1429, 1429, 2857, 2857, 2857, 1429, 4286, 2857, 2857, 2857, 2857, 1429, 1429, 2857, 2857, 2857, 5714, 1429, 1429, 2857, 1429, 1429, 2857, 2857, 2857, 5714, 1429, 1429, 2857, 2857, 2857, 2857, 4286, 1429, 2857, 2857, 17143, 2869, 1417, 1429, 2857, 2857, 2857, 1429, 5714, 1429, 2857, 2857, 2857, 1429, 1429, 2857, 2857, 2857, 5714, 1429, 1429, 2857, 2857, 2857, 1429, 4286, 2857, 2857, 1429, 1429, 2857, 1429, 1429, 2857, 2857, 2857, 5714, 1429, 1429, 2857, 2857, 2857, 1429, 5714, 1429, 2857, 2857, 2857, 1429, 1429, 2857, 2857, 2857, 5714, 1429, 1429, 2857, 1429, 1429, 2857, 11429, 1429, 1429, 1429, 1429, 8571, 2857, 2857, 4286, 1429, 11429, 2857, 5714, 2857, 2857, 2857, 5714, 2857, 8571, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 4286, 1429, 5714, 5714, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 4286, 1429, 11429, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 5714, 5714, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 8571, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 4286, 1429, 5714, 5714, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 4286, 1429, 11429, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 5714, 5714, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 2857, 4286, 1429, 11429, 15000};
const uint16_t NOTE_VALUES_2[] = {NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_GS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_GS4, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_GS4, NOTE_CS5, NOTE_C5, NOTE_REST, NOTE_GS4, NOTE_REST, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_C5, NOTE_DS5, NOTE_GS5, NOTE_G5, NOTE_GS5, NOTE_AS5, NOTE_F6, NOTE_DS6, NOTE_C5, NOTE_DS5, NOTE_GS5, NOTE_G5, NOTE_GS5, NOTE_AS5, NOTE_REST, NOTE_F5, NOTE_DS5, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_C5, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_G4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_G4, NOTE_E4, NOTE_REST, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_REST, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_CS4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_G4, NOTE_REST, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_REST, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_REST, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_G4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_REST, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_REST, NOTE_CS4, NOTE_CS4, NOTE_F4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_C5, NOTE_AS4, NOTE_REST, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_GS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_REST, NOTE_GS4, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_GS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_REST, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_DS5, NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_CS5, NOTE_DS5, NOTE_F5, NOTE_DS5, NOTE_CS5, NOTE_DS5, NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_CS5, NOTE_DS5, NOTE_REST, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_REST, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_CS4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_G4, NOTE_REST, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_REST, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_REST, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_G4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_REST, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_REST, NOTE_CS4, NOTE_CS4, NOTE_F4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_C5, NOTE_AS4, NOTE_REST, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_GS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_REST, NOTE_GS4, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_GS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_REST, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_G5, NOTE_DS5, NOTE_GS5, NOTE_G5, NOTE_DS5, NOTE_GS5, NOTE_G5, NOTE_DS5, NOTE_GS5, NOTE_G5, NOTE_DS5, NOTE_GS5, NOTE_G5, NOTE_GS5, NOTE_AS5, NOTE_CS6, NOTE_C6, NOTE_GS5, NOTE_G5, NOTE_DS5, NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_DS5, NOTE_GS4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_GS4, NOTE_F4, NOTE_GS4, NOTE_AS4, NOTE_B4, NOTE_C5, NOTE_CS5, NOTE_DS5, NOTE_C5, NOTE_GS4, NOTE_DS4, NOTE_F4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_CS5, NOTE_GS4, NOTE_G4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_GS4, NOTE_G4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_GS4, NOTE_G4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_REST, NOTE_C5, NOTE_GS4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_REST, NOTE_GS4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_AS4, NOTE_REST, NOTE_AS4, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_DS4, NOTE_AS4, NOTE_DS5, NOTE_REST, NOTE_DS5, NOTE_F5, NOTE_G5, NOTE_GS5, NOTE_DS5, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_REST, NOTE_GS5, NOTE_DS5, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_REST, NOTE_GS5, NOTE_DS5, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_REST, NOTE_GS5, NOTE_DS5, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_REST, NOTE_GS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_REST, NOTE_GS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_REST, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_REST, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_GS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_REST, NOTE_GS4, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_GS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_REST, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_REST, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_C5, NOTE_REST, NOTE_DS4, NOTE_F4, NOTE_CS5, NOTE_CS5, NOTE_REST, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_GS4, NOTE_DS5, NOTE_CS5, NOTE_DS5, NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_CS5, NOTE_DS5, NOTE_F5, NOTE_DS5, NOTE_CS5, NOTE_DS5, NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_CS5, NOTE_DS5, NOTE_F5, NOTE_DS5, NOTE_CS5, NOTE_DS5, NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_CS5, NOTE_DS5, NOTE_F5, NOTE_DS5, NOTE_CS5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_REST};
const uint16_t NOTE_DELAYS_2[] = {1650, 1744, 1744, 3401, 3488, 3488, 1831, 3401, 1831, 1744, 8372, 3750, 3488, 3488, 1831, 3401, 1831, 1744, 6715, 2006, 1744, 3401, 6802, 2006, 1744, 3401, 6802, 2006, 1744, 1744, 1839, 8278, 5676, 1650, 3401, 1831, 5058, 3576, 3488, 3488, 3488, 1831, 3401, 3488, 5145, 3576, 3488, 3488, 3488, 1831, 3401, 1926, 3307, 6802, 2100, 1650, 1744, 1744, 1744, 1744, 1744, 3401, 1831, 1744, 1744, 3401, 3488, 3488, 3488, 1831, 3401, 5145, 1919, 1744, 1744, 1744, 1744, 8372, 2187, 1650, 3401, 1831, 1744, 1744, 1744, 1744, 1744, 1744, 3401, 1831, 1744, 1744, 3401, 1831, 3401, 3488, 6802, 3844, 1650, 1744, 3401, 1831, 1744, 3401, 3488, 3488, 1831, 1744, 6715, 2006, 3401, 3488, 3488, 3488, 1831, 3401, 3488, 5145, 2013, 1650, 3401, 1831, 1744, 1744, 1744, 1744, 1744, 1744, 3401, 1831, 1744, 1744, 3401, 1831, 3401, 3488, 6802, 3844, 1650, 1744, 3401, 1831, 1744, 3401, 3488, 3488, 1831, 1744, 6715, 2006, 3401, 1831, 3401, 3488, 3488, 1831, 5058, 8990, 1650, 1744, 3401, 1831, 3401, 1831, 6715, 3663, 3488, 3488, 3488, 1831, 3401, 1831, 3401, 1926, 1650, 1744, 3401, 1831, 1744, 1744, 5058, 3576, 1831, 1744, 1744, 6715, 3844, 3307, 3488, 3488, 3488, 3488, 3488, 3488, 13430, 9426, 1650, 1744, 1744, 3401, 3488, 3488, 1831, 3401, 1831, 1744, 8372, 3750, 3488, 3488, 1831, 3401, 1831, 1744, 5058, 2013, 1650, 1744, 3401, 5145, 2013, 1650, 1744, 3401, 5145, 2013, 1650, 3401, 3488, 3488, 3488, 5145, 1919, 6715, 3663, 3488, 3488, 1831, 3401, 1831, 1744, 8372, 3750, 3488, 3488, 1831, 3401, 1831, 1744, 5058, 2013, 1650, 1744, 3401, 5145, 2013, 1650, 1744, 3401, 5145, 2013, 1650, 1744, 3401, 8459, 5676, 1650, 3401, 1831, 3401, 1831, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1839, 1650, 3401, 1831, 1744, 1744, 1744, 1744, 1744, 1744, 3401, 1831, 1744, 1744, 3401, 1831, 3401, 3488, 6802, 3844, 1650, 1744, 3401, 1831, 1744, 3401, 3488, 3488, 1831, 1744, 6715, 2006, 3401, 3488, 3488, 3488, 1831, 3401, 3488, 5145, 2013, 1650, 3401, 1831, 1744, 1744, 1744, 1744, 1744, 1744, 3401, 1831, 1744, 1744, 3401, 1831, 3401, 3488, 6802, 3844, 1650, 1744, 3401, 1831, 1744, 3401, 3488, 3488, 1831, 1744, 6715, 2006, 3401, 1831, 3401, 3488, 3488, 1831, 5058, 8990, 1650, 1744, 3401, 1831, 3401, 1831, 6715, 3663, 3488, 3488, 3488, 1831, 3401, 1831, 3401, 1926, 1650, 1744, 3401, 1831, 1744, 1744, 5058, 3576, 1831, 1744, 1744, 6715, 3844, 3307, 3488, 3488, 3488, 3488, 3488, 3488, 13430, 9426, 1650, 1744, 1744, 3401, 3488, 3488, 1831, 3401, 1831, 1744, 8372, 3750, 3488, 3488, 1831, 3401, 1831, 1744, 5058, 2013, 1650, 1744, 3401, 5145, 2013, 1650, 1744, 3401, 5145, 2013, 1650, 3401, 3488, 3488, 3488, 5145, 1919, 6715, 3663, 3488, 3488, 1831, 3401, 1831, 1744, 8372, 3750, 3488, 3488, 1831, 3401, 1831, 1744, 5058, 2013, 1650, 1744, 3401, 5145, 2013, 1650, 1744, 3401, 5145, 2013, 1650, 1744, 3401, 8459, 5676, 1650, 3401, 1831, 3401, 1831, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 5058, 5233, 5233, 5233, 3576, 3488, 1831, 1744, 1744, 10029, 2180, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 3401, 1003, 872, 3358, 3488, 3488, 3488, 5145, 5233, 5233, 5233, 3576, 3488, 5145, 5233, 5233, 5233, 3576, 3488, 5145, 5233, 5233, 5233, 3576, 3488, 5145, 5233, 5233, 3576, 1831, 1744, 1744, 1744, 6715, 2006, 1744, 1744, 1744, 6715, 2006, 3401, 3488, 3488, 1831, 3401, 1831, 1839, 6621, 2006, 1744, 1744, 3401, 3488, 1831, 3401, 1831, 1839, 4964, 3576, 3488, 3488, 5145, 1919, 6715, 5589, 1650, 1744, 1744, 1744, 1744, 1744, 1744, 3401, 1831, 3401, 1831, 1744, 1744, 3401, 1926, 1650, 1744, 1744, 3401, 3488, 3488, 1831, 3401, 1831, 1744, 6715, 2100, 3307, 3488, 3488, 1831, 3401, 1831, 1744, 6715, 2100, 3307, 3488, 3488, 1831, 3401, 1831, 1744, 6715, 2100, 3307, 3488, 3488, 1831, 3401, 1831, 1744, 6715, 2100, 3307, 3488, 3488, 1831, 3401, 1831, 1744, 6715, 2100, 3307, 3488, 3488, 1831, 3401, 1831, 1744, 5058, 2013, 1650, 1744, 3401, 5145, 2013, 1650, 1744, 3401, 5145, 2013, 1650, 1744, 3401, 8459, 7420, 1650, 1744, 1744, 1744, 8815, 1650, 1744, 1744, 3401, 3488, 3488, 1831, 3401, 1831, 1744, 8372, 3750, 3488, 3488, 1831, 3401, 1831, 1744, 5058, 2013, 1650, 1744, 3401, 5145, 2013, 1650, 1744, 3401, 5145, 2013, 1650, 3401, 3488, 3488, 3488, 5145, 1919, 6715, 3663, 3488, 3488, 1831, 3401, 1831, 1744, 8372, 3750, 3488, 3488, 1831, 3401, 1831, 1744, 5058, 2013, 1650, 1744, 3401, 5145, 2013, 1650, 1744, 3401, 5145, 2013, 1650, 3401, 1831, 8372, 5676, 1650, 3401, 1831, 3401, 1831, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 1744, 5058, 15174, 15000};

const uint8_t ADSR_VALUES[] = {0, 50, 75, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0, 0, 0};
const uint16_t* NOTE_VALUES[] = {NOTE_VALUES_1, NOTE_VALUES_2};
const uint16_t* NOTE_DELAYS[] = {NOTE_DELAYS_1, NOTE_DELAYS_2};
const uint32_t NOTE_SIZES[] = {sizeof(NOTE_VALUES_1) / sizeof(NOTE_VALUES_1[0]), sizeof(NOTE_VALUES_2) / sizeof(NOTE_VALUES_2[0])};
volatile uint16_t trackPtr = 0, notePtr = 0;

// LED
PORT_Type* RUNNING_LED_PORTS[] = {PORTB, PORTB, PORTB, PORTB, PORTE, PORTE, PORTE, PORTE};
GPIO_Type* RUNNING_LED_GPIOS[] = {PTB, PTB, PTB, PTB, PTE, PTE, PTE, PTE};
const uint8_t RUNNING_LED_PINS[] = {8, 9, 10, 11, 2, 3, 4, 5};

PORT_Type* FIXED_LED_PORT = PORTE;
GPIO_Type* FIXED_LED_GPIO = PTE;
const uint8_t FIXED_LED_PIN = 20;

// MOTOR
#define LEFT_MOTOR_FORWARD_PIN 1 // Port C Pin 1
#define RIGHT_MOTOR_FORWARD_PIN 2 // Port C Pin 2
#define LEFT_MOTOR_REVERSE_PIN 3 // Port C Pin 3
#define RIGHT_MOTOR_REVERSE_PIN 4 //Port C Pin 4
#define MOD_VALUE 7500 //period of PWM
#define HIGH_VALUE 3000 //lower this value to lower max speed

// UART
#define UART_BAUD_RATE 115200
#define UART_RX_PIN    23     // Port E Pin 23
#define UART2_INT_PRIO 128

volatile uint8_t direction = 8;
volatile uint8_t shouldPauseMusic = 0;

/**
Red Led: PTE20
Audio: PTB0
Front Left Wheel: PTC1
Back Left Wheel PTC3
*/
