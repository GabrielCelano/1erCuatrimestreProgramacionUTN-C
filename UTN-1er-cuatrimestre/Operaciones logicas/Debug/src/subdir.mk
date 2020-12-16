################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Operaciones\ logicas.c 

OBJS += \
./src/Operaciones\ logicas.o 

C_DEPS += \
./src/Operaciones\ logicas.d 


# Each subdirectory must supply rules for building sources it contributes
src/Operaciones\ logicas.o: ../src/Operaciones\ logicas.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Operaciones logicas.d" -MT"src/Operaciones\ logicas.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


