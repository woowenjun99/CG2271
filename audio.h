#include "macros.h"

void initAudioPWM() {
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
	SIM->SCGC6 |= SIM_SCGC6_TPM1_MASK;
	
	PORTB->PCR[AUDIO_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[AUDIO_PIN] |= PORT_PCR_MUX(3);
	
	SIM->SOPT2 &= ~SIM_SOPT2_TPMSRC_MASK;
	SIM->SOPT2 |= SIM_SOPT2_TPMSRC(1);
	
	TPM1_C0SC &= ~(TPM_CnSC_ELSB_MASK | TPM_CnSC_ELSA_MASK | TPM_CnSC_MSB_MASK | TPM_CnSC_MSA_MASK);
	TPM1_C0SC |= TPM_CnSC_ELSB(1) | TPM_CnSC_MSB(1);
	
	TPM1->SC |= TPM_SC_CPWMS_MASK;
	TPM1->SC &= ~((TPM_SC_CMOD_MASK) | (TPM_SC_PS_MASK));
	TPM1->SC |= (TPM_SC_CMOD(1) | TPM_SC_PS(7));
}

void audioThread(void* argument) {
    const uint16_t NOTES[] = {262, 262, 392, 392, 440, 440, 392};
    const uint16_t DURATIONS[] = {333, 333, 333, 333, 333, 333, 333};
    const uint32_t SIZE = sizeof(NOTES) / sizeof(NOTES[0]);
    uint32_t count = 0;
    uint8_t on = 1;
    
    initAudioPWM();
    while (1) {
        TPM1->MOD = SYSCLK / AUDIO_PRESCALAR / NOTES[count];
        TPM1_C0V = on ? (TPM1->MOD / AUDIO_VOLUME_DIVIDER) : 0;
        osDelay(AUDIO_DELAY(DURATIONS[count], on));
        on = !on;
        if (on) {
            count = count == SIZE - 1 ? 0 : count + 1;
        }
    }
}
