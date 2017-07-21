################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CalcSquareVolume.c \
../CalcSurfaceArea.c \
../DiceRoller.c \
../RecordData.c \
../WordHistogram.c \
../main.c 

OBJS += \
./CalcSquareVolume.o \
./CalcSurfaceArea.o \
./DiceRoller.o \
./RecordData.o \
./WordHistogram.o \
./main.o 

C_DEPS += \
./CalcSquareVolume.d \
./CalcSurfaceArea.d \
./DiceRoller.d \
./RecordData.d \
./WordHistogram.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/acurnutt/workspace/StdUtils" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


