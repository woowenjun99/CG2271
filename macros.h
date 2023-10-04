#pragma once

/// Includes all the macros that we will use.
#define RED_LED 	18
#define GREEN_LED	19
#define MASK(x)		(1 << (x))
#define PTB0_Pin 	0
#define PTB1_Pin	1

/// Include all the libaries that we will use.
#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"
#include "system_MKL25Z4.h"
