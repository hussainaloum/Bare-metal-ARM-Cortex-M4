#ifndef SYSTICK_H
#define SYSTICK_H

#include "nRF52833.h"


/****************************************
 * APIs supported by this UART driver
 ****************************************/
void SysTick_Init();
void delay_ms(uint32_t delay);
void nrfx_systick_delay_ms(uint32_t ms);

#endif /* SYSTICK_H */