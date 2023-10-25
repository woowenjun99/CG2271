#include "macros.h"

void UART2_IRQHandler(void) {
    NVIC_ClearPendingIRQ(UART2_IRQn);
    if (UART2->S1 & UART_S1_RDRF_MASK) {
        uint8_t data = UART2->D;
        rightWheelDutyCycle = ((data & 0b111000) >> 3) * 0.25;
        leftWheelDutyCycle = (data & 0b111) * 0.25;
        isReverse = data & MASK(6);
        isCompleted = data & MASK(7);
    }
}

void initUART(void) {
    SIM->SCGC4 |= SIM_SCGC4_UART2_MASK;
    SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;

    PORTE->PCR[UART_RX_PIN] &= ~PORT_PCR_MUX_MASK;
    PORTE->PCR[UART_RX_PIN] |= PORT_PCR_MUX(4);
    
    // Turns off the receiver (Page 754 of 807)
    UART2->C2 &= ~UART_C2_RE_MASK;
    
    uint32_t bus_clock = DEFAULT_SYSTEM_CLOCK / 2;
    uint32_t divisor = bus_clock / (UART_BAUD_RATE * 16);
    UART2->BDH = UART_BDH_SBR(divisor >> 8);
    UART2->BDL = UART_BDL_SBR(divisor);
    
    UART2->C1 = 0;
    UART2->S2 = 0;
    UART2->C3 = 0;
    
    // Turn on the receiver and the receive interrupt (Page 754 of 807)
    UART2->C2 |= UART_C2_RE_MASK | UART_C2_RIE_MASK;
    
    // Set IRQ for UART
    NVIC_ClearPendingIRQ(UART2_IRQn);
    NVIC_EnableIRQ(UART2_IRQn);
}
