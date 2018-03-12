################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/binary_tree.c \
../src/binary_tree_node.c \
../src/binary_tree_node_main.c \
../src/binary_tree_node_queue.c \
../src/traversal_callbacks.c 

OBJS += \
./src/binary_tree.o \
./src/binary_tree_node.o \
./src/binary_tree_node_main.o \
./src/binary_tree_node_queue.o \
./src/traversal_callbacks.o 

C_DEPS += \
./src/binary_tree.d \
./src/binary_tree_node.d \
./src/binary_tree_node_main.d \
./src/binary_tree_node_queue.d \
./src/traversal_callbacks.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


