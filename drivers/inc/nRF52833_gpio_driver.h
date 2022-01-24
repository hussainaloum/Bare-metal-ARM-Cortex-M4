#ifndef NRF52833_GPIO_DRIVER_H
#define NRF52833_GPIO_DRIVER_H

#include "nRF52833.h"

/**
 *  This is a configuration strcuture for a GPIO 
 */

typedef struct
{
    uint8_t pin_dir;                //Pin direction
    uint8_t pin_input_buff;         //Connect or disconnect input buffer
    uint8_t pin_pupd;               //Pull(up/down) configuration
    uint8_t pin_drive;              //Drive configuration
    uint8_t pin_sensing;            //Pin sensing mechanism
}GPIO_PinConfig_t;

/**
 * This is a handle structure for GPIO 
 */

typedef struct
{
    GPIO_PinConfig_t    GPIO_PinConfig;
    GPIO_RegDef_t       *pGPIOPx;           //Holds the address of GPIO Port X
}GPIO_Handle_t;

/* GPIO initialization function */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle, uint8_t PinNumber);

/* Data read and write functions */
void GPIO_WriteToOutputPin(GPIO_Handle_t *pGPIOHandle, uint8_t PinNumber, uint8_t Value);
bool GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOPx, uint8_t PinNumber);

/* GPIO pin directions macros */
#define GPIO_INPUT          0
#define GPIO_OUTPUT         1

/* GPIO pin pull up and pull down configuration macros */
#define GPIO_PU             3
#define GPIO_PD             1
#define GPIO_NO_PUPD        0

/* GPIO pin input buffer */
#define GPIO_INPUT_CONN     0
#define GPIO_INPUT_DIS      1

/* GPIO pin drive configuration macros */
#define GPIO_DRIVE_S0S1     0
#define GPIO_DRIVE_H0S1     1
#define GPIO_DRIVE_S0H1     2
#define GPIO_DRIVE_H0H1     3
#define GPIO_DRIVE_D0S1     4
#define GPIO_DRIVE_D0H1     5
#define GPIO_DRIVE_S0D1     6
#define GPIO_DRIVE_H0D1     7

/* GPIO pin sense configuration macros */
#define GPIO_SENSE_DIS      0
#define GPIO_SENSE_HI       2
#define GPIO_SENSE_LO       3

#endif /* NRF52833_GPIO_DRIVER_H */