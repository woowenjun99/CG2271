 #include "macros.h"
 
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
	SIM->SOPT2 |= ~SIM_SOPT2_TPMSRC(1);
 
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



/** ======================== Motor Logic =========================== */

void stop() {
	//Left motor stop
	TPM0_C0V = 0;
	TPM0_C2V = 0;
	
	//Right motor stop
	TPM0_C1V = 0;
	TPM0_C3V = 0;
}

void forwardLeft(int motor_high, int motor_turn) {
	//Left motor forward turn
	TPM0_C0V = motor_turn;
	TPM0_C2V = 0;
	
	//Right motor forward high
	TPM0_C1V = motor_high;
	TPM0_C3V = 0;
	
}

void forwardRight(int motor_high, int motor_turn) {
	//Left motor forward high
	TPM0_C0V = motor_high;
	TPM0_C2V = 0;
	
	//Right motor forward turn
	TPM0_C1V = motor_turn;
	TPM0_C3V = 0;
	
}

void reverseLeft(int motor_high, int motor_turn) {
	//Left motor reverse turn
	TPM0_C0V = motor_turn;
	TPM0_C2V = 0;
	
	//Right motor reverse high
	TPM0_C1V = 0;
	TPM0_C3V = motor_high;
}

void reverseRight(int motor_high, int motor_turn) {
	//Left motor reverse high
	TPM0_C0V = 0;
	TPM0_C2V = motor_high;
	
	//Right motor reverse turn
	TPM0_C1V = 0;
	TPM0_C3V = motor_turn;
}

void motorThread(void *argument) {
	initMotorPWM();

	
	while (1) {
		//to be changed to update values received from UART
		float x = 0; //negative for left, positive for right
		float y = 1; //negative for reverse, positive for forward
		float speed = 1;
		
		int motor_high = HIGH_VALUE * speed;
		
		//stop
		if (x == 0 && y == 0) stop();
		
		//reverse
		if (y < 0) {
			if (x < 0) {
				int motor_turn = HIGH_VALUE * speed * (1 + x);
				reverseLeft(motor_high, motor_turn);
			} else {
				int motor_turn = HIGH_VALUE * speed * (1 - x);
				reverseRight(motor_high, motor_turn);
			}
		} else { 
			//forward
			if (x < 0) {
				int motor_turn = HIGH_VALUE * speed * (1 + x);
				forwardLeft(motor_high, motor_turn);
			} else {
				int motor_turn = HIGH_VALUE * speed * (1 - x);
				forwardRight(motor_high, motor_turn);
			}
		}
	}
}
