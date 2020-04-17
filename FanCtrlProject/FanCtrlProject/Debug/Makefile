################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../Drivers \
../Info_n_Testing


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../BuzzApp.c \
../Drivers/Adc.c \
../Drivers/Gpio.c \
../Drivers/Lcd.c \
../Drivers/Pwm.c \
../Drivers/SevenSeg.c \
../Drivers/Timer.c \
../LcdApp.c \
../App.c \
../MotorSwingApp.c \
../SevenSegApp.c \
../SpeedApp.c \
../TimerApp.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
BuzzApp.o \
Drivers/Adc.o \
Drivers/Gpio.o \
Drivers/Lcd.o \
Drivers/Pwm.o \
Drivers/SevenSeg.o \
Drivers/Timer.o \
LcdApp.o \
App.o \
MotorSwingApp.o \
SevenSegApp.o \
SpeedApp.o \
TimerApp.o

OBJS_AS_ARGS +=  \
BuzzApp.o \
Drivers/Adc.o \
Drivers/Gpio.o \
Drivers/Lcd.o \
Drivers/Pwm.o \
Drivers/SevenSeg.o \
Drivers/Timer.o \
LcdApp.o \
App.o \
MotorSwingApp.o \
SevenSegApp.o \
SpeedApp.o \
TimerApp.o

C_DEPS +=  \
BuzzApp.d \
Drivers/Adc.d \
Drivers/Gpio.d \
Drivers/Lcd.d \
Drivers/Pwm.d \
Drivers/SevenSeg.d \
Drivers/Timer.d \
LcdApp.d \
App.d \
MotorSwingApp.d \
SevenSegApp.d \
SpeedApp.d \
TimerApp.d

C_DEPS_AS_ARGS +=  \
BuzzApp.d \
Drivers/Adc.d \
Drivers/Gpio.d \
Drivers/Lcd.d \
Drivers/Pwm.d \
Drivers/SevenSeg.d \
Drivers/Timer.d \
LcdApp.d \
App.d \
MotorSwingApp.d \
SevenSegApp.d \
SpeedApp.d \
TimerApp.d

OUTPUT_FILE_PATH +=FanCtrlProject.elf

OUTPUT_FILE_PATH_AS_ARGS +=FanCtrlProject.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler



























./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"../Drivers"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Drivers/%.o: ../Drivers/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"../Drivers"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="FanCtrlProject.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega32"  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "FanCtrlProject.elf" "FanCtrlProject.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "FanCtrlProject.elf" "FanCtrlProject.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "FanCtrlProject.elf" > "FanCtrlProject.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "FanCtrlProject.elf" "FanCtrlProject.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "FanCtrlProject.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "FanCtrlProject.elf" "FanCtrlProject.a" "FanCtrlProject.hex" "FanCtrlProject.lss" "FanCtrlProject.eep" "FanCtrlProject.map" "FanCtrlProject.srec" "FanCtrlProject.usersignatures"
	