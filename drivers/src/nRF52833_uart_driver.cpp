#include "nRF52833_uart_driver.h"

/*************************************************************
 * @name        UART_Init
 * @brief		Initialize UART peripheral
 * @inputs
 *		pUARTHandle:        UART Handle
 *
 * @return		None
 * @Note		None
*************************************************************/
void UART_Init(UART_Handle_t *pUARTHandle)
{
	//1- Set the baud rate
	if(pUARTHandle->UART_Config.BaudRate <= UART_Baud1M)
	{
		pUARTHandle->pUARTx->BAUDRATE = pUARTHandle->UART_Config.BaudRate;
	}
	else		//if the baud rate exceeds the support limit
	{
		pUARTHandle->pUARTx->BAUDRATE = UART_Baud1M;
	}

	//2- Set parity control
	if(pUARTHandle->UART_Config.ParityControl == UART_ParityIncluded)
	{
		pUARTHandle->pUARTx->CONFIG |= (UART_ParityIncluded << UART_CONFIG_PARITY_BIT_POS);
	}
	else
	{
		pUARTHandle->pUARTx->CONFIG |= (UART_ParityExcluded << UART_CONFIG_PARITY_BIT_POS);
	}

	//3- Hardware flow control
	if(pUARTHandle->UART_Config.HWFlowControl == UART_HWFC_EN)
	{
		pUARTHandle->pUARTx->CONFIG |= (UART_HWFC_EN << UART_CONFIG_HWFC_BIT_POS);
	}
	else
	{
		pUARTHandle->pUARTx->CONFIG |= (UART_HWFC_DIS << UART_CONFIG_HWFC_BIT_POS);
	}

	//4- Number of stop bits
	if(pUARTHandle->UART_Config.NoOfStopBits == UART_STOP_TWO)
	{
		pUARTHandle->pUARTx->CONFIG |= (UART_STOP_TWO << UART_CONFIG_STOP_BIT_POS);
	}
	else
	{
		pUARTHandle->pUARTx->CONFIG |= (UART_STOP_ONE << UART_CONFIG_STOP_BIT_POS);
	}

	//Disable UART before configuring
	pUARTHandle->pUARTx->ENABLE = (uint32_t)UART_DISABLE;

	//Assign the registers RXD and TXD to physical pins
	uint32_t temp = 0x00;

	temp |= 17;					//Pin number
	temp &= ~(1 << 5);			//GPIO port number 0
	temp &= ~(1<< 31);			//Connect
	pUARTHandle->pUARTx->PSEL_TXD = temp;

	temp = 0x00;

	temp |= 19;					//Pin number
	temp &= ~(1 << 5);			//GPIO port number 0
	temp &= ~(1<< 31);			//Connect
	pUARTHandle->pUARTx->PSEL_RXD = temp;

	//Enable UART
	pUARTHandle->pUARTx->ENABLE = (uint32_t)UART_ENABLE;
}

/*************************************************************
 * @name		UART_SendData
 * @brief		Send data on UART peripheral
 * @inputs
 *		pUARTHandle:        UART Handle
 *      pData:				buffer for data to be sent
 * 		Length:				length of data in bytes         
 *
 * @return		None
 * @Note		None
*************************************************************/
void UART_SendData(UART_Handle_t *pUARTHandle, uint8_t *pData, uint32_t Length)
{	
	//1- Trigger STARTTX task
	for(uint32_t i = 0; i < Length; i++)
	{
		pUARTHandle->pUARTx->TXD = *pData;							//load one byte of data to the TXD register
		pUARTHandle->pUARTx->TASKS_STARTTX = 0x01;					//Generate start bit

		while(pUARTHandle->pUARTx->EVENTS_TXDRDY == UART_EV_NGENERATED);
		++pData;


		//clear TX register
		pUARTHandle->pUARTx->EVENTS_TXDRDY = 0x00;
	}
	pUARTHandle->pUARTx->TASKS_STOPTX = 0x01;						//Generate stop bit
}

/*************************************************************
 * @name		LFXO_Init
 * @brief		Initialize and start the low frequency external clock
 * @inputs		None    
 *
 * @return		None
 * @Note		None
*************************************************************/
void LFXO_Init()
{
	CLOCK_RegDef_t *pClock = CLOCK;
	//1- select the preferred clock source in register LFCLKSRC
	pClock->LFCLKSRC |= (1 << 0);									//Xtal
	pClock->LFCLKSRC &= ~(1 << 16);
	pClock->LFCLKSRC &= ~(1 << 17);

	//2- trigger the LFCLKSTART task
	pClock->TASKS_LFCLKSTART = 0x01;

	//3- wait for the LFCLKSTARTED event flag
	while(!(pClock->EVENTS_LFCLKSTARTED & 0x01));
}