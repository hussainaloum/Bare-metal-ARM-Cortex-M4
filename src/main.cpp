/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Hussain Aloum
  * @version V1.0
  * @brief   main file, which sends a message over UART when a button is pressed.
  ******************************************************************************
*/


/** Notes:
 *  Check the layout of the Dev board before picking a GPIO pin,
 *  some pins are not available to be used such as P0.01
 */

#include "nRF52833_gpio_driver.h"
#include "nRF52833_uart_driver.h"
#include <cstring>												//for strlen();


char data[] = "Lets get this working";
char data2[] = "Second message";

int main()
{
    //Create a GPIO Handle
    GPIO_Handle_t GPIOHandle_IN;

    //Configure the initial values of GPIO as input
    GPIOHandle_IN.pGPIOPx = GPIOP0;
    GPIOHandle_IN.GPIO_PinConfig.pin_dir = GPIO_INPUT;
    GPIOHandle_IN.GPIO_PinConfig.pin_drive = GPIO_DRIVE_S0S1;
    GPIOHandle_IN.GPIO_PinConfig.pin_input_buff = GPIO_INPUT_CONN;
    GPIOHandle_IN.GPIO_PinConfig.pin_pupd = GPIO_PU;
    GPIOHandle_IN.GPIO_PinConfig.pin_sensing = GPIO_SENSE_LO;
	GPIOHandle_IN.pGPIOPx->DETECTMODE = 0x01;						//Use the latched LDETECT behavior
    
    //Initialize a specific pin in GPIO
    GPIO_Init(&GPIOHandle_IN, 11);

	//Creat UART Handle
	UART_Handle_t UARTHandle;

	UARTHandle.pUARTx = UART0;
	UARTHandle.UART_Config.BaudRate = UART_Baud9600;
	UARTHandle.UART_Config.HWFlowControl = UART_HWFC_DIS;
	UARTHandle.UART_Config.NoOfStopBits = UART_STOP_ONE;
	UARTHandle.UART_Config.ParityControl = UART_ParityExcluded;

	//initialize UART
	UART_Init(&UARTHandle);
	//initialize high frequency external oscillator
	HFXO_Init();												/* If LFXO is used make sure to include a delay
																	long enough after each SendData command.		
																	take a look at Electrical specs in the UART 
																	section in the datasheet					*/

	while(1)
	{
		//if button 1 is pressed
		if((GPIOHandle_IN.pGPIOPx->IN & (0x01 << 11)) == 0x00)
		{
			UART_SendData(&UARTHandle, (uint8_t *)data, strlen(data));
			UART_SendData(&UARTHandle, (uint8_t *)data2, strlen(data2));
		}
	}
}