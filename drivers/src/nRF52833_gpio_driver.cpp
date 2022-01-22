#include "nRF52833_gpio_driver.h"

void GPIO_Init(GPIO_Handle_t *GPIOHandle, uint8_t PinNumber)
{
    //1- Initialize the direction of pin input/output
    if(GPIOHandle->GPIO_PinConfig.pin_dir == GPIO_INPUT)
    {
        GPIOHandle->pGPIOPx->PIN_CNF[PinNumber] |= (GPIO_INPUT << GPIO_PIN_CNF_DIR_BIT_POS);
    }
    else
    {
        GPIOHandle->pGPIOPx->PIN_CNF[PinNumber] |= (GPIO_OUTPUT << GPIO_PIN_CNF_DIR_BIT_POS);
    }

    //2- Connect or disconnect input buffer (default Disconnect)
    if(GPIOHandle->GPIO_PinConfig.pin_input_buff == GPIO_INPUT_CONN)
    {
        GPIOHandle->pGPIOPx->PIN_CNF[PinNumber] |= (GPIO_INPUT_CONN << GPIO_PIN_CNF_INPUT_BIT_POS);
    }
    else
    {
        GPIOHandle->pGPIOPx->PIN_CNF[PinNumber] |= (GPIO_INPUT_DIS << GPIO_PIN_CNF_INPUT_BIT_POS);
    }

    //3- Enable/Disable pull-up and pull-down resistors
    if(GPIOHandle->GPIO_PinConfig.pin_pupd == GPIO_PU)
    {
        GPIOHandle->pGPIOPx->PIN_CNF[PinNumber] |= (GPIO_PU << GPIO_PIN_CNF_PULL_BIT_POS);
    }
    else if(GPIOHandle->GPIO_PinConfig.pin_pupd == GPIO_PD)
    {
        GPIOHandle->pGPIOPx->PIN_CNF[PinNumber] |= (GPIO_PD << GPIO_PIN_CNF_PULL_BIT_POS);
    }
    else
    {
        GPIOHandle->pGPIOPx->PIN_CNF[PinNumber] |= (GPIO_NO_PUPD << GPIO_PIN_CNF_PULL_BIT_POS);
    }

    //4- Drive configuration            (Add the other drive methods when needed)
    if(GPIOHandle->GPIO_PinConfig.pin_drive == GPIO_DRIVE_S0S1)
    {
        GPIOHandle->pGPIOPx->PIN_CNF[PinNumber] |= (GPIO_DRIVE_S0S1 << GPIO_PIN_CNF_DRIVE_BIT_POS);
    }

    //5- Configure pin sensing mechanism
    if(GPIOHandle->GPIO_PinConfig.pin_sensing == GPIO_SENSE_HI)
    {
        GPIOHandle->pGPIOPx->PIN_CNF[PinNumber] |= (GPIO_SENSE_HI << GPIO_PIN_CNF_SENSE_BIT_POS);
    }
    else if(GPIOHandle->GPIO_PinConfig.pin_sensing == GPIO_SENSE_LO)
    {
        GPIOHandle->pGPIOPx->PIN_CNF[PinNumber] |= (GPIO_SENSE_LO << GPIO_PIN_CNF_SENSE_BIT_POS);
    }
    else
    {
        GPIOHandle->pGPIOPx->PIN_CNF[PinNumber] |= (GPIO_SENSE_DIS << GPIO_PIN_CNF_SENSE_BIT_POS);
    }
}

void GPIO_WriteToOutputPin(GPIO_Handle_t *GPIOHandle, uint8_t PinNumber, uint8_t Value)
{
    if(Value == 1)
    {
        GPIOHandle->pGPIOPx->PIN_CNF[PinNumber] |= (GPIO_DRIVE_S0H1 << GPIO_PIN_CNF_DRIVE_BIT_POS);
    }
    else
    {
        // GPIOHandle->pGPIOPx->PIN_CNF[PinNumber] &= ~(0x01 << GPIO_PIN_CNF_DRIVE_BIT_POS);
        GPIOHandle->pGPIOPx->PIN_CNF[PinNumber] |= (GPIO_DRIVE_D0S1 << GPIO_PIN_CNF_DRIVE_BIT_POS);
        //GPIOHandle->pGPIOPx->OUTCLR |= (0x01 << PinNumber);
    }
}


bool GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOPx, uint8_t PinNumber)
{
    return 0;
}
