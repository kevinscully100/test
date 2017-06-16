################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/startup_gcc/newlib_stubs.c 

S_UPPER_SRCS += \
../CMSIS/startup_gcc/startup_m2sxxx.S 

OBJS += \
./CMSIS/startup_gcc/newlib_stubs.o \
./CMSIS/startup_gcc/startup_m2sxxx.o 

S_UPPER_DEPS += \
./CMSIS/startup_gcc/startup_m2sxxx.d 

C_DEPS += \
./CMSIS/startup_gcc/newlib_stubs.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/startup_gcc/%.o: ../CMSIS/startup_gcc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\Microsemi\SoftConsole_v5.1.0.19\SoftConsole_v5.1\extras\workspace.examples\smartfusion2-cortex-m3-blinky" -I"C:\Microsemi\SoftConsole_v5.1.0.19\SoftConsole_v5.1\extras\workspace.examples\smartfusion2-cortex-m3-blinky\CMSIS" -I"C:\Microsemi\SoftConsole_v5.1.0.19\SoftConsole_v5.1\extras\workspace.examples\smartfusion2-cortex-m3-blinky\CMSIS\startup_gcc" -I"C:\Microsemi\SoftConsole_v5.1.0.19\SoftConsole_v5.1\extras\workspace.examples\smartfusion2-cortex-m3-blinky\drivers\mss_gpio" -I"C:\Microsemi\SoftConsole_v5.1.0.19\SoftConsole_v5.1\extras\workspace.examples\smartfusion2-cortex-m3-blinky\drivers_config" -I"C:\Microsemi\SoftConsole_v5.1.0.19\SoftConsole_v5.1\extras\workspace.examples\smartfusion2-cortex-m3-blinky\drivers_config\sys_config" -I"C:\Microsemi\SoftConsole_v5.1.0.19\SoftConsole_v5.1\extras\workspace.examples\smartfusion2-cortex-m3-blinky\hal" -I"C:\Microsemi\SoftConsole_v5.1.0.19\SoftConsole_v5.1\extras\workspace.examples\smartfusion2-cortex-m3-blinky\hal\CortexM3" -I"C:\Microsemi\SoftConsole_v5.1.0.19\SoftConsole_v5.1\extras\workspace.examples\smartfusion2-cortex-m3-blinky\hal\CortexM3\GNU" -std=gnu11 --specs=cmsis.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CMSIS/startup_gcc/%.o: ../CMSIS/startup_gcc/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


