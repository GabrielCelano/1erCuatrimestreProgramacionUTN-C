################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Clase\ 1.c 

OBJS += \
./src/Clase\ 1.o 

C_DEPS += \
./src/Clase\ 1.d 


# Each subdirectory must supply rules for building sources it contributes
src/Clase\ 1.o: ../src/Clase\ 1.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Clase 1.d" -MT"src/Clase\ 1.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


