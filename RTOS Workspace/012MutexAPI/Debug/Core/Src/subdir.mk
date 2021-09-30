################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_hal_timebase_tim.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_hal_timebase_tim.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_hal_timebase_tim.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/main.o: ../Core/Src/main.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/FreeRTOS/include" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/Config" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/OS" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/SEGGER" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Core/Inc" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/CMSIS/Include" -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/stm32f4xx_hal_msp.o: ../Core/Src/stm32f4xx_hal_msp.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/FreeRTOS/include" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/Config" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/OS" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/SEGGER" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Core/Inc" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/CMSIS/Include" -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32f4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/stm32f4xx_hal_timebase_tim.o: ../Core/Src/stm32f4xx_hal_timebase_tim.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/FreeRTOS/include" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/Config" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/OS" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/SEGGER" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Core/Inc" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/CMSIS/Include" -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32f4xx_hal_timebase_tim.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/stm32f4xx_it.o: ../Core/Src/stm32f4xx_it.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/FreeRTOS/include" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/Config" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/OS" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/SEGGER" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Core/Inc" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/CMSIS/Include" -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32f4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/system_stm32f4xx.o: ../Core/Src/system_stm32f4xx.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/FreeRTOS/include" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/Config" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/OS" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/common/ThirdParty/SEGGER/SEGGER" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Core/Inc" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Oliver/Desktop/FastBit Embedded Brain Academy/CubeIDE Workspaces/Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging/RTOS Workspace/012MutexAPI/Drivers/CMSIS/Include" -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/system_stm32f4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

