#include "nRF52833_gpio_driver.h"

int main()
{
    // uint32_t P0 = 0x50000000;
    // uint32_t DIR = 0x514;
    // uint32_t taddr = (P0 + DIR);
    GPIO_Handle_t GPIOHandle;

    GPIOHandle.pGPIOPx = GPIOP0;
    GPIOHandle.GPIO_PinConfig.pin_dir = GPIO_OUTPUT;
    GPIOHandle.GPIO_PinConfig.pin_drive = GPIO_DRIVE_S0H1;
    GPIOHandle.GPIO_PinConfig.pin_input_buff = GPIO_INPUT_DIS;
    GPIOHandle.GPIO_PinConfig.pin_pupd = GPIO_NO_PUPD;
    GPIOHandle.GPIO_PinConfig.pin_sensing = GPIO_SENSE_DIS;
    
    //GPIOHandle.pGPIOPx = GPIOP0;

    GPIO_Init(&GPIOHandle, 1);

    GPIO_WriteToOutputPin(&GPIOHandle, 1, 0);

    // GPIOP0->DIR |= (0x01 << 0);

    // uint32_t *ptaddr = (uint32_t *)0x50000514;
    // *ptaddr |= (0x01 << 13);

    // uint32_t *ptaddr1 = (uint32_t *)0x50000514;
    // *ptaddr1 &= ~(0x01 << 13);

    for(;;);

}
