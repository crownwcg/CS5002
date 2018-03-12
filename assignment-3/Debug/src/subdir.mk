################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/array_deque.c \
../src/array_list.c \
../src/arraylist_crawler.c \
../src/arraylist_crawler_main.c \
../src/arraylist_iterator.c \
../src/messagepriorityqueue.c 

OBJS += \
./src/array_deque.o \
./src/array_list.o \
./src/arraylist_crawler.o \
./src/arraylist_crawler_main.o \
./src/arraylist_iterator.o \
./src/messagepriorityqueue.o 

C_DEPS += \
./src/array_deque.d \
./src/array_list.d \
./src/arraylist_crawler.d \
./src/arraylist_crawler_main.d \
./src/arraylist_iterator.d \
./src/messagepriorityqueue.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


