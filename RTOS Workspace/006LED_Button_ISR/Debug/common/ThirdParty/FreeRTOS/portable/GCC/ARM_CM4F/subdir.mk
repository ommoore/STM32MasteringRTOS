################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Oliver/Desktop/FastBit\ Embedded\ Brain\ Academy/CubeIDE\ Workspaces/Mastering\ RTOS\ -\ Hands\ on\ FreeRTOS\ and\ STM32Fx\ with\ Debugging/RTOS\ Workspace/common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/port.o: C:/Users/Oliver/Desktop/FastBit\ Embedded\ Brain\ Academy/CubeIDE\ Workspaces/Mastering\ RTOS\ -\ Hands\ on\ FreeRTOS\ and\ STM32Fx\ with\ Debugging/RTOS\ Workspace/common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/port.c common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/FreeRTOS/include" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/Config" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/OS" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/SEGGER" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/006LED_Button_ISR/Core/Inc" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/006LED_Button_ISR/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/006LED_Button_ISR/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/006LED_Button_ISR/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/006LED_Button_ISR/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

