================================================================================
              SmartFusion MSS GPIO simple blink example
================================================================================

This example project demonstrates the use of MSS GPIO. It demonstrates the use
of GPIO as OUT pins.
--------------------------------------------------------------------------------
                            How to use this example
--------------------------------------------------------------------------------
This project blinks the on-board LEDs using the GPIO out functionality.

--------------------------------------------------------------------------------
                                Target hardware
--------------------------------------------------------------------------------
This example project is targeted for SmartFusion A2F-DEV-KIT board.
   NOTE:   This sample project expects that the MSS GPIOs are connected to
           external pins through the FPGA fabric as follows:
               - MSS_GPIO_0: output to pin B19
               - MSS_GPIO_1: output to pin B20
               - MSS_GPIO_2: output to pin C19
               - MSS_GPIO_3: output to pin H17


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                          Silicon revision dependencies
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
This example is built to execute on an A2F500 device (SmartFusion).