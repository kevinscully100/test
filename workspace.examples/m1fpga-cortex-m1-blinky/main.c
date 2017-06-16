/*******************************************************************************
 * (c) Copyright 2016 Microsemi Corporation.  All rights reserved.
 *
 */

#include "hw_platform.h"
#include "drivers/CoreGPIO/core_gpio.h"

#include "./CMSIS/cortexm1_cfg.h"
#include "./CMSIS/system_cortexm1_cfg.h"

/*
 * CoreGPIO instance data.
 */
gpio_instance_t g_gpio;

static void delay(void)
{
    volatile uint32_t delay_count = SystemCoreClock / 128u;

    while(delay_count > 0u)
    {
        --delay_count;
    }
}

/******************************************************************************
 * GPIO instance data.
 *****************************************************************************/
gpio_instance_t g_gpio;

/*-------------------------------------------------------------------------*//**
 * main() function.
 */
int main()
{
    /*
	* CMSIS function- sets firmware system clock to Libero definition
	*/
    SystemCoreClockUpdate();

    /**************************************************************************
     * Initialize the CoreGPIO driver with the base address of the CoreGPIO
     * instance to use and the initial state of the outputs.
     *************************************************************************/
     GPIO_init( &g_gpio, COREGPIO_BASE_ADDR, GPIO_APB_32_BITS_BUS );

#if 0
     /*
      * Configure GPIOs if CoreGPIO not using fixed config in Libero
      */
     GPIO_config( &g_gpio, GPIO_0, GPIO_OUTPUT_MODE );
     GPIO_config( &g_gpio, GPIO_1, GPIO_OUTPUT_MODE );
     GPIO_config( &g_gpio, GPIO_2, GPIO_OUTPUT_MODE );
     GPIO_config( &g_gpio, GPIO_3, GPIO_OUTPUT_MODE );
#endif

    /*
     * Infinite loop.
     */
     for(;;)
     {
         uint32_t gpio_pattern;
         /*
          * Decrement delay counter.
          */
         delay();

         /*
          * Toggle GPIO outputs
          */
         gpio_pattern = GPIO_get_outputs( &g_gpio );
         gpio_pattern ^= 0xf;
         GPIO_set_outputs( &g_gpio, gpio_pattern );
     }

     return 0;
}
