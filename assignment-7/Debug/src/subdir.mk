################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hash_map.c \
../src/hash_map_iterator.c \
../src/hash_set.c \
../src/hash_set_iterator.c \
../src/hash_set_main.c \
../src/map_entry.c 

OBJS += \
./src/hash_map.o \
./src/hash_map_iterator.o \
./src/hash_set.o \
./src/hash_set_iterator.o \
./src/hash_set_main.o \
./src/map_entry.o 

C_DEPS += \
./src/hash_map.d \
./src/hash_map_iterator.d \
./src/hash_set.d \
./src/hash_set_iterator.d \
./src/hash_set_main.d \
./src/map_entry.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


