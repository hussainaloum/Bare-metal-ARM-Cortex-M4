/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Hussain Aloum
  * @version V1.0
  * @brief   main file, which controls GPIO pins to light LEDs in a pattern
  ******************************************************************************
*/


/** Notes:
 *  Check the layout of the Dev board before picking a GPIO pin,
 *  some pins are not available to be used such as P0.01
 */

#include "nRF52833_gpio_driver.h"

void delay(uint32_t seconds);

int main()
{
    //Create a GPIO Handle
    GPIO_Handle_t GPIOHandle;

    //Configure the initial values of GPIO
    GPIOHandle.pGPIOPx = GPIOP0;
    GPIOHandle.GPIO_PinConfig.pin_dir = GPIO_OUTPUT;
    GPIOHandle.GPIO_PinConfig.pin_drive = GPIO_DRIVE_S0S1;
    GPIOHandle.GPIO_PinConfig.pin_input_buff = GPIO_INPUT_DIS;
    GPIOHandle.GPIO_PinConfig.pin_pupd = GPIO_NO_PUPD;
    GPIOHandle.GPIO_PinConfig.pin_sensing = GPIO_SENSE_DIS;
    
    //Initialize a specific pin in GPIO
    GPIO_Init(&GPIOHandle, 13);
    GPIO_Init(&GPIOHandle, 14);
    GPIO_Init(&GPIOHandle, 15);
    GPIO_Init(&GPIOHandle, 16);

    GPIO_WriteToOutputPin(&GPIOHandle, 13, 1);          //Turn off LED according to schematic (LED connected to VDD)
    GPIO_WriteToOutputPin(&GPIOHandle, 14, 1);          //Turn off LED according to schematic (LED connected to VDD)
    GPIO_WriteToOutputPin(&GPIOHandle, 15, 1);          //Turn off LED according to schematic (LED connected to VDD)
    GPIO_WriteToOutputPin(&GPIOHandle, 16, 1);          //Turn off LED according to schematic (LED connected to VDD)

    while(1)
    {
        GPIO_WriteToOutputPin(&GPIOHandle, 13, 0);
        GPIO_WriteToOutputPin(&GPIOHandle, 16, 0);
        delay(5000000);
        GPIO_WriteToOutputPin(&GPIOHandle, 13, 1);          //Turn off LED according to schematic (LED connected to VDD)
        GPIO_WriteToOutputPin(&GPIOHandle, 16, 1);          //Turn off LED according to schematic (LED connected to VDD)
        GPIO_WriteToOutputPin(&GPIOHandle, 15, 0);
        GPIO_WriteToOutputPin(&GPIOHandle, 14, 0);
         
        delay(5000000);

        GPIO_WriteToOutputPin(&GPIOHandle, 15, 1);          //Turn off LED according to schematic (LED connected to VDD)
        GPIO_WriteToOutputPin(&GPIOHandle, 14, 1);          //Turn off LED according to schematic (LED connected to VDD)
        GPIO_WriteToOutputPin(&GPIOHandle, 16, 1);          //Turn off LED according to schematic (LED connected to VDD)
        GPIO_WriteToOutputPin(&GPIOHandle, 13, 1);          //Turn off LED according to schematic (LED connected to VDD)
    }

}

void delay(uint32_t seconds)
{
    for(uint32_t i = 0; i < seconds; i++)
    {
        //Do nothing
    }
}