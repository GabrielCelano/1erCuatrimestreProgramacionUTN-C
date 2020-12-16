################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/electrodomesticos.c \
../src/informes.c \
../src/main.c \
../src/reparaciones.c \
../src/utn.c 

OBJS += \
./src/electrodomesticos.o \
./src/informes.o \
./src/main.o \
./src/reparaciones.o \
./src/utn.o 

C_DEPS += \
./src/electrodomesticos.d \
./src/informes.d \
./src/main.d \
./src/reparaciones.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


