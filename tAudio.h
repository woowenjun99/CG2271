#include "macros.h"

void initPWM(void) {
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;
	
	PORTC->PCR[AUDIO_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[AUDIO_PIN] |= PORT_PCR_MUX(4);
	
	SIM->SOPT2 &= ~SIM_SOPT2_TPMSRC_MASK;
	SIM->SOPT2 |= SIM_SOPT2_TPMSRC(1);
	
	/// Configure the MOD and C0V value here
	TPM0->MOD = 7500;
	TPM0_C0V = 0.5 * (7500 + 1) - 1;
	
	/// Configure the MOD and C0V value here
	
	TPM0->SC &= ~((TPM_SC_CMOD_MASK) | (TPM_SC_PS_MASK));
	TPM0->SC |= (TPM_SC_CMOD(1) | TPM_SC_PS(7));
	TPM0->SC &= ~TPM_SC_CPWMS_MASK;
	
	TPM0_C0SC &= ~(TPM_CnSC_ELSB_MASK | TPM_CnSC_ELSA_MASK | TPM_CnSC_MSB_MASK | TPM_CnSC_MSA_MASK);
	TPM0_C0SC |= TPM_CnSC_ELSB(1) | TPM_CnSC_MSB(1);
}

void audioThread() {
    const uint16_t NOTES[] = {440, 330, 220, 110};
    const uint16_t DURATIONS[] = {1200, 1200, 1200, 1200};
    const int SIZE = sizeof(NOTES) / sizeof(NOTES[0]);
    int count = 0;
    
    while (1) {
        TPM0->MOD = 375000 / NOTES[count];
        TPM0_C0V = TPM0->MOD / 2;
        osDelay(DURATIONS[count]);
        count = count == SIZE - 1 ? 0 : count + 1;
    }
}
