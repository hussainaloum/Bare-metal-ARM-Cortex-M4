#ifndef NRF52833_H
#define NRF52833_H

#include <cstdint>

#define __VO    volatile
#define __VOC   volatile const

/* Base addresses of Memory and SRAM */
#define FLASH_BASEADDR      0x00000000U
#define SRAM_BASEADDR       0x20000000U

/* Base addresses of APB and AHB Bus Peripherals */
#define APB_BASEADDR        0x40000000U
#define AHB_BASEADDR        0x50000000U

/* Base addresses of peripherals on APB bus */
#define GPIOP0_BASEADDR     AHB_BASEADDR
#define GPIOP1_BASEADDR     (AHB_BASEADDR + 0x300)
#define CLOCK_BASEADDR      APB_BASEADDR
#define UART_BASEADDR       (APB_BASEADDR + 0x2000)


/**
 * **********************************************************************
 *                      Peripheral register definitions
 * **********************************************************************
*/

/**
 * GPIO P0-P1
*/
typedef struct 
{
	__VOC   uint32_t RESERVERD[321];
	__VO    uint32_t OUT;                      // Write GPIO port
	__VO    uint32_t OUTSET;                   // Set individual bits in GPIO port
	__VO    uint32_t OUTCLR;                   // Clear individual bits in GPIO port
	__VO    uint32_t IN;                       // Read GPIO port
	__VO    uint32_t DIR;                      // DIrection of GPIO pins
	__VO    uint32_t DIRSET;                   // DIR set register
	__VO    uint32_t DIRCLR;                   // Dir clear register
	__VO    uint32_t LATCH;                    /* Latch register indicating what GPIO pins
												that have met the criteria set in the
												PIN_CNF[n].SENSE registers
											*/
	__VO    uint32_t DETECTMODE;               /* Select between default DETECT signal
												behavior and LDETECT mode
											*/
	__VOC   uint32_t RESERVERD1[118];
	__VO    uint32_t PIN_CNF[32];               // Configuration of GPIO pins
}GPIO_RegDef_t;

/**
 * Clock
*/
typedef struct
{
	__VO    uint32_t TASKS_HFCLKSTART;          // Start HFXO crystal oscillator
	__VO    uint32_t TASKS_HFCLKSTOP;           // Stop HFXO crystal oscillator
	__VO    uint32_t TASKS_LFCLKSTART;          // Start LFCLK
	__VO    uint32_t TASKS_LFCLKSTOP;           // Stop LFCLK
	__VO    uint32_t TASKS_CAL;                 // Start calibration of LFRC
	__VO    uint32_t TASKS_CTSTART;             // Start calibration timer
	__VO    uint32_t TASKS_CTSTOP;              // Stop calibration timer
	__VOC   uint32_t RESERVED[57];              
	__VO    uint32_t EVENTS_HFCLKSTARTED;       // HFXO crystal oscillator started
	__VO    uint32_t EVENTS_LFCLKSTARTED;       // LFCLK started
	__VOC   uint32_t RESERVED1;
	__VO    uint32_t EVENTS_DONE;               // Calibration of LFRC completed
	__VO    uint32_t EVENTS_CTTO;               // Calibration timer timeout
	__VOC   uint32_t RESERVED2[5];
	__VO    uint32_t EVENTS_CTSTARTED;          // Calibration timer has been started and is ready to process new tasks
	__VO    uint32_t EVENTS_CTSTOPPED;          // Calibration timer has been stopped and is ready to process new tasks
	__VOC   uint32_t RESERVED3[117];
	__VO    uint32_t INTENSET;                  // Enable interrupt
	__VO    uint32_t INTENCLR;                  // Disable interrupt
	__VOC   uint32_t RESERVED4[63];
	__VO    uint32_t HFCLKRUN;                  // Status indicating that HFCLKSTART task has been triggered
	__VO    uint32_t HFCLKSTAT;                 // HFCLK status
	__VOC   uint32_t RESERVED5;         
	__VO    uint32_t LFCLKRUN;                  // Status indicating that LFCLKSTART task has been triggered
	__VO    uint32_t LFCLKSTAT;                 // LFCLK status
	__VO    uint32_t LFCLKSRCCOPY;              // Copy of LFCLKSRC register, set when LFCLKSTART task was triggered
	__VOC   uint32_t RESERVED6[62];
	__VO    uint32_t LFCLKSRC;                  // Clock source for the LFCLK
	__VOC   uint32_t RESERVED7[3];
	__VO    uint32_t HFXODEBOUNCE;              /* HFXO debounce time. The HFXO is started by
													triggering the TASKS_HFCLKSTART
												*/
	__VO    uint32_t LFXODEBOUNCE;              /* LFXO debounce time. The LFXO is started by
													triggering the TASKS_LFCLKSTART task when the
													LFCLKSRC register is configured for Xtal.
												*/
	__VOC   uint32_t RESERVED8[2];
	__VO    uint32_t CTIV;                      // Calibration timer interval
	__VOC   uint32_t RESERVED9[8];
	__VO    uint32_t TRACECONFIG;               // Clocking options for the trace port debug interface
}CLOCK_RegDef_t;

/**
 * UART
*/

typedef struct
{
	__VO    uint32_t TASKS_STARTRX;             //Start UART receiver
	__VO    uint32_t TASKS_STOPRX;              //Stop UART receiver
	__VO    uint32_t TASKS_STARTTX;             //Start UART transmitter
	__VO    uint32_t TASKS_STOPTX;              //Stop UART transmitter
	__VOC   uint32_t RESERVED0[3];
	__VO    uint32_t TASKS_SUSPEND;             //Suspend UART
	__VOC   uint32_t RESERVED1[56];
	__VO    uint32_t EVENTS_CTS;                //CTS is activated (set low). Clear to Send
	__VO    uint32_t EVENTS_NCTS;               //CTS is deactivated (set high). Not Clear To Send.
	__VO    uint32_t EVENTS_RXDRDY;             //Data received in RXD
	__VOC   uint32_t RESERVED2[4];
	__VO    uint32_t EVENTS_TXDRDY;             //Data received in RXD
	__VOC   uint32_t RESERVED3;
	__VO    uint32_t EVENTS_ERROR;              //Error detected
	__VOC   uint32_t RESERVED4[7];
	__VO    uint32_t EVENTS_RXTO;               //Receiver timeout
	__VOC   uint32_t RESERVED5[46];
	__VO    uint32_t SHORTS;                    //Shortcuts between local events and tasks
	__VOC   uint32_t RESERVED6[64];
	__VO    uint32_t INTENSET;                  //Enable interrupt
	__VO    uint32_t INTENCLR;                  //Disable interrupt
	__VOC   uint32_t RESERVED7[93];
	__VO    uint32_t ERRORSRC;                  //Error source
	__VOC   uint32_t RESERVED8[31];
	__VO    uint32_t ENABLE;                    //Enable UART
	__VOC   uint32_t RESERVED9;
	__VO    uint32_t PSEL_RTS;                  //Pin select for RTS
	__VO    uint32_t PSEL_TXD;                  //Pin select for TXD
	__VO    uint32_t PSEL_CTS;                  //Pin select for CTS
	__VO    uint32_t PSEL_RXD;                  //Pin select for RXD
	__VO    uint32_t RXD;                       //RXD register
	__VO    uint32_t TXD;                       //TXD register
	__VOC   uint32_t RESERVED10;
	__VO    uint32_t BAUDRATE;                  //Baud rate. Accuracy depends on the HFCLK source selected.
	__VOC   uint32_t RESERVED11[17];
	__VO    uint32_t CONFIG;                    //Configuration of parity and hardware flow control
}UART_RegDef_t;


/**
 * **********************************************************************
 *                      Peripheral register definitions
 * **********************************************************************
*/

#define GPIOP0          ((GPIO_RegDef_t *)GPIOP0_BASEADDR)
#define GPIOP1          ((GPIO_RegDef_t *)GPIOP1_BASEADDR)

#define CLOCK           ((CLOCK_RegDef_t *)CLOCK_BASEADDR)

#define UART0           ((UART_RegDef_t *)UART_BASEADDR)

/**
 * **********************************************************************
 *                      Bit positions for peripherals
 * **********************************************************************
*/

/* GPIO bit positions */
#define GPIO_PIN_CNF_DIR_BIT_POS            0
#define GPIO_PIN_CNF_INPUT_BIT_POS          1
#define GPIO_PIN_CNF_PULL_BIT_POS           2
#define GPIO_PIN_CNF_DRIVE_BIT_POS          8
#define GPIO_PIN_CNF_SENSE_BIT_POS          16

/* UART bit postions */
#define UART_CONFIG_HWFC_BIT_POS            0
#define UART_CONFIG_PARITY_BIT_POS          1
#define UART_CONFIG_STOP_BIT_POS            4
#define UART_CONFIG_PARITYTYPE_BIT_POS      8

#endif  /* NRF52833_H */