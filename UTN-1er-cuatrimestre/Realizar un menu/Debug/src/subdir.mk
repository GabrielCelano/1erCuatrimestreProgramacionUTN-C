################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Realizar\ un\ menu.c 

OBJS += \
./src/Realizar\ un\ menu.o 

C_DEPS += \
./src/Realizar\ un\ menu.d 


# Each subdirectory must supply rules for building sources it contributes
src/Realizar\ un\ menu.o: ../src/Realizar\ un\ menu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Realizar un menu.d" -MT"src/Realizar\ un\ menu.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


