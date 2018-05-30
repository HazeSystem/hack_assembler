################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/hack_assembler.cpp \
../src/instruction.cpp 

OBJS += \
./src/hack_assembler.o \
./src/instruction.o 

CPP_DEPS += \
./src/hack_assembler.d \
./src/instruction.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"D:\cygwin64\lib\gcc\x86_64-pc-cygwin\6.4.0\include\c++" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


