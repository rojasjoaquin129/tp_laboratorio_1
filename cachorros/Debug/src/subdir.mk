################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LinkedList.c \
../src/cachorro.c \
../src/cachorros.c \
../src/controller.c \
../src/parser.c \
../src/utn.c 

OBJS += \
./src/LinkedList.o \
./src/cachorro.o \
./src/cachorros.o \
./src/controller.o \
./src/parser.o \
./src/utn.o 

C_DEPS += \
./src/LinkedList.d \
./src/cachorro.d \
./src/cachorros.d \
./src/controller.d \
./src/parser.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


