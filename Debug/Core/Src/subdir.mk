################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/LiquidCrystal.c \
../Core/Src/bullets.c \
../Core/Src/characters.c \
../Core/Src/config.c \
../Core/Src/freertos.c \
../Core/Src/keypad.c \
../Core/Src/lcd.c \
../Core/Src/main.c \
../Core/Src/screen_about.c \
../Core/Src/screen_difflevel.c \
../Core/Src/screen_finish.c \
../Core/Src/screen_intro.c \
../Core/Src/screen_menu.c \
../Core/Src/screen_name.c \
../Core/Src/screenmanager.c \
../Core/Src/stm32f3xx_hal_msp.c \
../Core/Src/stm32f3xx_hal_timebase_tim.c \
../Core/Src/stm32f3xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f3xx.c \
../Core/Src/timehandler.c 

C_DEPS += \
./Core/Src/LiquidCrystal.d \
./Core/Src/bullets.d \
./Core/Src/characters.d \
./Core/Src/config.d \
./Core/Src/freertos.d \
./Core/Src/keypad.d \
./Core/Src/lcd.d \
./Core/Src/main.d \
./Core/Src/screen_about.d \
./Core/Src/screen_difflevel.d \
./Core/Src/screen_finish.d \
./Core/Src/screen_intro.d \
./Core/Src/screen_menu.d \
./Core/Src/screen_name.d \
./Core/Src/screenmanager.d \
./Core/Src/stm32f3xx_hal_msp.d \
./Core/Src/stm32f3xx_hal_timebase_tim.d \
./Core/Src/stm32f3xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f3xx.d \
./Core/Src/timehandler.d 

OBJS += \
./Core/Src/LiquidCrystal.o \
./Core/Src/bullets.o \
./Core/Src/characters.o \
./Core/Src/config.o \
./Core/Src/freertos.o \
./Core/Src/keypad.o \
./Core/Src/lcd.o \
./Core/Src/main.o \
./Core/Src/screen_about.o \
./Core/Src/screen_difflevel.o \
./Core/Src/screen_finish.o \
./Core/Src/screen_intro.o \
./Core/Src/screen_menu.o \
./Core/Src/screen_name.o \
./Core/Src/screenmanager.o \
./Core/Src/stm32f3xx_hal_msp.o \
./Core/Src/stm32f3xx_hal_timebase_tim.o \
./Core/Src/stm32f3xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f3xx.o \
./Core/Src/timehandler.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

