/*******************************************************************************
 * (c) Copyright 2009-2015 Microsemi Corporation.  All rights reserved.
 *
 *  Simple SmartFusion microcontroller subsystem (MSS) GPIO example program.
 *  This sample program is targeted at the SmartFusion Advanced Development Kit.
 *  It blinks the development board's LEDs using a delay loop.
 *
 *  Please read the README.txt file in the root folder of this project to know more. 
 *
 *
 * SVN $Revision: 7838 $
 * SVN $Date: 2015-09-17 18:20:04 +0530 (Thu, 17 Sep 2015) $
 */
#include "drivers/mss_gpio/mss_gpio.h"
#include "drivers/mss_watchdog/mss_watchdog.h"

/*
 * Delay loop down counter load value.
 */
#define DELAY_LOAD_VALUE     0x00100000

/*-------------------------------------------------------------------------*//**
 * main() function.
 */
int main()
{
    volatile int32_t delay_count = 0;
    
    /*
     * Disable watchdog. 
     */
    MSS_WD_disable();
    
    /*
     * Initialize MSS GPIOs.
     */
    MSS_GPIO_init();
    
    /*
     * Configure MSS GPIOs.
     */
    MSS_GPIO_config( MSS_GPIO_0 , MSS_GPIO_OUTPUT_MODE );
    MSS_GPIO_config( MSS_GPIO_1 , MSS_GPIO_OUTPUT_MODE );
    MSS_GPIO_config( MSS_GPIO_2 , MSS_GPIO_OUTPUT_MODE );
    MSS_GPIO_config( MSS_GPIO_3 , MSS_GPIO_OUTPUT_MODE );
    
    /*
     * Set initial delay used to blink the LED.
     */
    delay_count = DELAY_LOAD_VALUE;
    
    /*
     * Infinite loop.
     */
    for(;;)
    {
        uint32_t gpio_pattern;
        /*
         * Decrement delay counter.
         */
        --delay_count;
        
        /*
         * Check if delay expired.
         */
        if ( delay_count <= 0 )
        {
            /*
             * Reload delay counter.
             */
            delay_count = DELAY_LOAD_VALUE;
            
            /*
             * Toggle GPIO output pattern by doing an exclusive OR of all
             * pattern bits with ones.
             */
            gpio_pattern = MSS_GPIO_get_outputs();
            gpio_pattern ^= 0xFFFFFFFF;
            MSS_GPIO_set_outputs( gpio_pattern );
        }
    }
    
    return 0;
}
