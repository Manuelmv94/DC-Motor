################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/SCI.c" \
"../Sources/StringUtils.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/SCI.c \
../Sources/StringUtils.c \
../Sources/main.c \

OBJS += \
./Sources/SCI_c.obj \
./Sources/StringUtils_c.obj \
./Sources/main_c.obj \

OBJS_QUOTED += \
"./Sources/SCI_c.obj" \
"./Sources/StringUtils_c.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/SCI_c.d \
./Sources/StringUtils_c.d \
./Sources/main_c.d \

C_DEPS_QUOTED += \
"./Sources/SCI_c.d" \
"./Sources/StringUtils_c.d" \
"./Sources/main_c.d" \

OBJS_OS_FORMAT += \
./Sources/SCI_c.obj \
./Sources/StringUtils_c.obj \
./Sources/main_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/SCI_c.obj: ../Sources/SCI.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/SCI.args" -ObjN="Sources/SCI_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/StringUtils_c.obj: ../Sources/StringUtils.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/StringUtils.args" -ObjN="Sources/StringUtils_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


