################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: comp_one

dependents:
	-cd /home/acurnutt/workspace/StdUtils/Debug && $(MAKE) all

# Tool invocations
comp_one: $(OBJS) $(USER_OBJS) /home/acurnutt/workspace/StdUtils/Debug/libStdUtils.a
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc -static -L"/home/acurnutt/workspace/StdUtils/Debug" -o "comp_one" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) comp_one
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
/home/acurnutt/workspace/StdUtils/Debug/libStdUtils.a:

-include ../makefile.targets
