#include "macros.h"
#include "uart.h"
 
/** ======================== Enable Ports for PWM =========================== */
void initMotorPWM() {
	/// Clock gating logic to PORT C
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
    
	/// Set PTC1 to TPM0_CH0
	PORTC->PCR[LEFT_MOTOR_FORWARD_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[LEFT_MOTOR_FORWARD_PIN] |= PORT_PCR_MUX(4);
	
	/// Set PTC2 to TPM0_CH1
	PORTC->PCR[RIGHT_MOTOR_FORWARD_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[RIGHT_MOTOR_FORWARD_PIN] |= PORT_PCR_MUX(4);
	
	/// Set PTC3 to TPM0_CH2
	PORTC->PCR[LEFT_MOTOR_REVERSE_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[LEFT_MOTOR_REVERSE_PIN] |= PORT_PCR_MUX(4);
	
	/// Set PTC4 to TPM0_CH3
	PORTC->PCR[RIGHT_MOTOR_REVERSE_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[RIGHT_MOTOR_REVERSE_PIN] |= PORT_PCR_MUX(4);
    
	/// Enable clock gating for Timer0
	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;
	
	/// Set clock for TPM Module
	SIM->SOPT2 &= ~SIM_SOPT2_TPMSRC_MASK;
	SIM->SOPT2 |= SIM_SOPT2_TPMSRC(1);
 
	// Set Mod value to 7500
	TPM0->MOD = MOD_VALUE;
 
	/// Set clock to count-up, prescaler = 111 (divide by 128)
	TPM0->SC &= ~((TPM_SC_CMOD_MASK) | (TPM_SC_PS_MASK));
	TPM0->SC |= (TPM_SC_CMOD(1) | TPM_SC_PS(7));
	TPM0->SC &= ~(TPM_SC_CPWMS_MASK);
		
	/// Enable PWM on TPM0 for Channel 0-3
	TPM0_C0SC &= ~((TPM_CnSC_ELSB_MASK) | (TPM_CnSC_ELSA_MASK) | (TPM_CnSC_MSB_MASK) | (TPM_CnSC_MSA_MASK));
	TPM0_C0SC |= (TPM_CnSC_ELSB(1) | TPM_CnSC_MSB(1));
	TPM0_C1SC &= ~((TPM_CnSC_ELSB_MASK) | (TPM_CnSC_ELSA_MASK) | (TPM_CnSC_MSB_MASK) | (TPM_CnSC_MSA_MASK));
	TPM0_C1SC |= (TPM_CnSC_ELSB(1) | TPM_CnSC_MSB(1));
	TPM0_C2SC &= ~((TPM_CnSC_ELSB_MASK) | (TPM_CnSC_ELSA_MASK) | (TPM_CnSC_MSB_MASK) | (TPM_CnSC_MSA_MASK));
	TPM0_C2SC |= (TPM_CnSC_ELSB(1) | TPM_CnSC_MSB(1));
	TPM0_C3SC &= ~((TPM_CnSC_ELSB_MASK) | (TPM_CnSC_ELSA_MASK) | (TPM_CnSC_MSB_MASK) | (TPM_CnSC_MSA_MASK));
	TPM0_C3SC |= (TPM_CnSC_ELSB(1) | TPM_CnSC_MSB(1));
}

void motorThread(void *argument) {
	initMotorPWM();

	while (1) {
        // Left Forward Motor
		TPM0_C0V = !isReverse ? leftWheelDutyCycle * HIGH_VALUE : 0;
        // Right Forward Motor
		TPM0_C1V = !isReverse ? rightWheelDutyCycle * HIGH_VALUE : 0;
        // Left Reverse Motor
		TPM0_C2V = isReverse ? rightWheelDutyCycle * HIGH_VALUE : 0;
        // Right Reverse motor
		TPM0_C3V = isReverse ? leftWheelDutyCycle * HIGH_VALUE : 0;
	}
}
