################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/linked_array.c \
../src/linked_list.c \
../src/linked_list_iterator.c \
../src/linked_list_iterator_main.c 

OBJS += \
./src/linked_array.o \
./src/linked_list.o \
./src/linked_list_iterator.o \
./src/linked_list_iterator_main.o 

C_DEPS += \
./src/linked_array.d \
./src/linked_list.d \
./src/linked_list_iterator.d \
./src/linked_list_iterator_main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


