#include <nRF52833.h>

#define RELOADVALUE		0xFFFFFFU


/*************************************************************
 * @name		SysTick_Init
 * @brief		Initialize System timer (SystIck)
 * @inputs		None
 *
 * @return		None
 * @Note		None
*************************************************************/
void SysTick_Init()
{
	//Provide reload value
	SYSTICK->SYST_RVR = RELOADVALUE;

	//Clear current reload value
	SYSTICK->SYST_CVR	= 0x00;

	//Program Control and Status register
	SYSTICK->SYST_CSR	= 0x05;
}

/*************************************************************
 * @name		delay_ms
 * @brief		produce a delay in milliseconds
 * @inputs
 *		ms:		delay in milliseconds      
 *
 * @return		None
 * @Note		None
*************************************************************/
void delay_ms(uint32_t ms)
{
	uint32_t r = ms % 64;				//if ms = 5 millisec, then r = 5

	r = r * (64000000U / 1000U);		//Ticks in a 1000ms (1sec)
										//64000000Hz is the clock frequency

	const uint32_t start_value = SYSTICK->SYST_CVR;		//Get the current counter value
	while((RELOADVALUE & (start_value - SYSTICK->SYST_CVR)) < r)
	{
		//Do nothing
	}
}