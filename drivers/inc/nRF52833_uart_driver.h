#ifndef NRF52833_UART_DRIVER_H
#define NRF52833_UART_DRIVER_H

#include "nRF52833.h"

/**
 *  This is a configuration strcuture for a UART 
 */

typedef struct
{
	uint32_t    BaudRate;                   //Configure Clock source to be the external crystal for stable communication
	uint8_t     ParityControl;
	uint8_t     HWFlowControl;
	uint8_t     NoOfStopBits;        
}UART_Config_t;

/**
 *  This is a handle strcuture for a UART 
 */

typedef struct
{
	UART_Config_t   UART_Config;
	UART_RegDef_t   *pUARTx;               //Holds the address of UARTx
}UART_Handle_t;


/****************************************
 * APIs supported by this UART driver
 ****************************************/

/* UART initialization function */
void UART_Init(UART_Handle_t *pUARTHandle);

/* UART send data function */
void UART_SendData(UART_Handle_t *pUARTHandle, uint8_t *pData, uint32_t Length);

/* LFCLK control */
void LFXO_Init();


/* UART baud rate macros */
#define UART_Baud1200       0x0004F000
#define UART_Baud2400       0x0009D000
#define UART_Baud4800       0x0013B000
#define UART_Baud9600       0x00275000
#define UART_Baud14400      0x003B0000
#define UART_Baud19200      0x004EA000
#define UART_Baud28800      0x0075F000
#define UART_Baud31250      0x00800000
#define UART_Baud38400      0x009D5000
#define UART_Baud56000      0x00E50000
#define UART_Baud57600      0x00EBF000  
#define UART_Baud76800      0x013A9000
#define UART_Baud115200     0x01D7E000
#define UART_Baud230400     0x03AFB000
#define UART_Baud250000     0x04000000
#define UART_Baud460800     0x075F7000
#define UART_Baud921600     0x0EBED000
#define UART_Baud1M         0x10000000

/* UART parity control macros */
#define UART_ParityExcluded 0x00
#define UART_ParityIncluded 0x07

/* UART hardware flow control macros */
#define UART_HWFC_DIS       0x00
#define UART_HWFC_EN        0x01

/* UART stop bit number macros */
#define UART_STOP_ONE       0x00
#define UART_STOP_TWO       0x01

/* UART event macros */
#define UART_EV_NGENERATED  0x00
#define UART_EV_GENERATED   0x01

/* UART enable macros*/
#define UART_DISABLE		0x00
#define UART_ENABLE			0x04

#endif /* NRF52833_UART_DRIVER_H */