# Bare-metal-ARM-Cortex-M4
This project uses the Nordic Semiconductor nRF52833 DK to send messages over the UART peripheral.   
This project runs bare-metal, meaning it doesn't run on an OS. It prodives accurate delays using the SysTick peripheral in ARM Cortex-M4.  

### Drivers included:  
UART  
GPIO  
SysTick  

Picture below shows an accurate delay of 5ms using SysTick
![Screenshot 2022-01-29 220018](https://user-images.githubusercontent.com/36559536/151686111-b90fb89e-0769-41f4-af5d-44ae6c1048eb.png)
