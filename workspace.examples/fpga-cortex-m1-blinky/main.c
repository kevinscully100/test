/*******************************************************************************
 * (c) Copyright 2016 Microsemi Corporation.  All rights reserved.
 *
 * Blinks LED from systick interrupt
 * Printf() and Scanf() targeted to UART using CoreUART and functions enabled in CMSIS
 *
 * The following memory map is required in the Libero design to run this example:
 * CORTEXM1
 * CoreAHBLSRAM       0x00000000
 * CoreAHBLSRAM       0x30000000
 * CoreGPIO           0x41000000
 * CoreUARTapb        0x42000000
 *
 * In a production design, the ram at 0x00000000 will be replaced by UPROM.

 * The CoreAHBLite facilitates swapping memory at AHB slot 0 and 1 using an input, and this can be used
 * to simplify swapping between debugging and production mode.

 * Note: To enable the tick interrupt, the OS extensions must be ticked when instantiating the CortexM1.
 *
 * SVN $Revision: 8353 $
 * SVN $Date: 2016-03-30 15:21:22 +0100 (Wed, 30 Mar 2016) $
 */
#include "hw_platform.h"
#include <stdio.h>
#include "drivers/CoreGPIO/core_gpio.h"
#include "drivers/CoreUARTapb/core_uart_apb.h"
#include <string.h>

#include "./CMSIS/cortexm1_cfg.h"
#include "./CMSIS/system_cortexm1_cfg.h"


/*
 * Delay loop down counter load value.
 */
#define DELAY_LOAD_VALUE     0x00008000

/*
 * CoreGPIO instance data.
 */
gpio_instance_t g_gpio;

volatile uint32_t g_10ms_count;


/******************************************************************************
 * Baud value to achieve a 57600 baud rate with a 24MHz system clock.
 * This value is calculated using the following equation:
 *      BAUD_VALUE = (CLOCK / (16 * BAUD_RATE)) - 1
 *****************************************************************************/
#define BAUD_VALUE_57600    25

#define MAX_RX_DATA_SIZE 	100


/******************************************************************************
 * Timer load value. This value is calculated to result in the timer timing
 * out after after 1 second with a system clock of 24MHz and the timer
 * prescaler set to divide by 1024.
 *****************************************************************************/
#define TIMER_LOAD_VALUE    23437

/******************************************************************************
 * GPIO instance data.
 *****************************************************************************/
gpio_instance_t g_gpio;


/******************************************************************************
 * locally defined functions
 *****************************************************************************/
void mscc_post_hw_cfg_init(void);



/*-------------------------------------------------------------------------*//**
 * main() function.
 */
int main()
{
    volatile int32_t delay_count;
    uint8_t rx_data[MAX_RX_DATA_SIZE];
    size_t rx_size;
    uint32_t frequency = 100;
    char value;

    /*
	* CMSIS function- sets firmware system clock to Libero definition
	*/
    SystemCoreClockUpdate();

    NVIC_SetPriority(SysTick_IRQn, 0xFFu);  /* Lowest possible priority */
    SysTick_Config(SystemCoreClock/100);	/* CMSIS function which configures systick */


    printf("Hello, is there anybody there?\r\n");


    /**************************************************************************
     * Initialize the CoreGPIO driver with the base address of the CoreGPIO
     * instance to use and the initial state of the outputs.
     *************************************************************************/
     GPIO_init( &g_gpio, COREGPIO_BASE_ADDR, GPIO_APB_32_BITS_BUS );

    /**************************************************************************
     * Configure the GPIOs.
     *************************************************************************/
     GPIO_set_output( &g_gpio, GPIO_0, 0x00 );

    /*
     * Infinite loop.
     */
    for(;;)
    {
		printf("Is it me your looking for?\r\n");
		scanf("%c", &value);
		switch(value)
		{
			case '1':
				printf("I'm the one!\r\n");
				break;
		}
    }
    return 0;
}


/*------------------------------------------------------------------------------
 * Count the number of elapsed milliseconds (SysTick_Handler is called every
 * 10mS so the resolution will be 10ms). Rolls over every 49 days or so...
 *
 * Should be safe to read g_10ms_count from elsewhere.
 * Note: For SysTick_Handler to work, OS extensions must be enabled in Libero Cortex-M1 dialog
 */
__attribute__((__interrupt__)) void SysTick_Handler( void )
{
    uint32_t gpio_pattern;
    static uint8_t count;
    /*
     * Toggle GPIO output pattern by doing an exclusive OR of all
     * pattern bits with ones.
     */
    if(count++>100)
    {
        gpio_pattern = GPIO_get_outputs( &g_gpio );
        gpio_pattern ^= 0x00000002;
        GPIO_set_outputs( &g_gpio, gpio_pattern );
        count=0;
    }

    g_10ms_count += 10;

     /*
      * For neatness, if we roll over, reset cleanly back to 0 so the count
      * always goes up in proper 10s.
      */
    if(g_10ms_count < 10)
        g_10ms_count = 0;

}

/***************************************************************************//**
* Non Maskable Interrupt.
*/
__attribute__((__interrupt__)) void NMI_Handler( void )
{
    while( 1 )
    {
        ;
    }
}


/*------------------------------------------------------------------------------
 * mscc_post_hw_cfg_init(void)
 */
void mscc_post_hw_cfg_init(void)
{

}




