
################################################################################
# Automatically-generated file. Do not edit!
################################################################################

ifdef SystemRoot
	SHELL = cmd.exe
	MK_DIR = mkdir
else
	ifeq ($(shell uname), Linux)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), CYGWIN)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), MINGW32)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), MINGW64)
		MK_DIR = mkdir -p
	endif
endif

# List the subdirectories for creating object files
SUB_DIRS +=  \
 \
hpl/tc \
hpl/pmc \
hal/src \
hpl/xdmac \
same70b/armcc/Device/Source \
hal/utils/src \
examples \
same70b/armcc/Device/Source/ARM \
hpl/core

# List the object files
OBJS +=  \
hal/src/hal_io.o \
hpl/xdmac/hpl_xdmac.o \
hal/src/hal_timer.o \
same70b/armcc/Device/Source/system_same70q21b.o \
hal/src/hal_delay.o \
hpl/core/hpl_init.o \
hal/utils/src/utils_list.o \
hal/utils/src/utils_assert.o \
atmel_start.o \
hpl/pmc/hpl_pmc.o \
hal/src/hal_init.o \
examples/driver_examples.o \
led_flasher_main.o \
driver_init.o \
hal/src/hal_gpio.o \
hal/utils/src/utils_event.o \
hal/src/hal_sleep.o \
hpl/pmc/hpl_sleep.o \
hpl/core/hpl_core_m7_base.o \
hpl/tc/hpl_tc.o \
hal/src/hal_atomic.o \
same70b/armcc/Device/Source/ARM/startup_SAME70.o

OBJS_AS_ARGS +=  \
"hal/src/hal_io.o" \
"hpl/xdmac/hpl_xdmac.o" \
"hal/src/hal_timer.o" \
"same70b/armcc/Device/Source/system_same70q21b.o" \
"hal/src/hal_delay.o" \
"hpl/core/hpl_init.o" \
"hal/utils/src/utils_list.o" \
"hal/utils/src/utils_assert.o" \
"atmel_start.o" \
"hpl/pmc/hpl_pmc.o" \
"hal/src/hal_init.o" \
"examples/driver_examples.o" \
"led_flasher_main.o" \
"driver_init.o" \
"hal/src/hal_gpio.o" \
"hal/utils/src/utils_event.o" \
"hal/src/hal_sleep.o" \
"hpl/pmc/hpl_sleep.o" \
"hpl/core/hpl_core_m7_base.o" \
"hpl/tc/hpl_tc.o" \
"hal/src/hal_atomic.o" \
"same70b/armcc/Device/Source/ARM/startup_SAME70.o"

# List the dependency files
DEPS := $(OBJS:%.o=%.d)

DEPS_AS_ARGS +=  \
"hal/src/hal_gpio.d" \
"hal/src/hal_io.d" \
"hpl/xdmac/hpl_xdmac.d" \
"same70b/armcc/Device/Source/system_same70q21b.d" \
"hal/src/hal_timer.d" \
"hal/utils/src/utils_list.d" \
"hal/utils/src/utils_assert.d" \
"hal/src/hal_delay.d" \
"hpl/core/hpl_init.d" \
"hal/src/hal_init.d" \
"hpl/pmc/hpl_pmc.d" \
"driver_init.d" \
"led_flasher_main.d" \
"examples/driver_examples.d" \
"hal/src/hal_sleep.d" \
"hal/utils/src/utils_event.d" \
"atmel_start.d" \
"hal/src/hal_atomic.d" \
"hpl/tc/hpl_tc.d" \
"hpl/core/hpl_core_m7_base.d" \
"same70b/armcc/Device/Source/ARM/startup_SAME70.d" \
"hpl/pmc/hpl_sleep.d"

OUTPUT_FILE_NAME :=AtmelStart
QUOTE := "
OUTPUT_FILE_PATH +=$(OUTPUT_FILE_NAME).elf
OUTPUT_FILE_PATH_AS_ARGS +=$(OUTPUT_FILE_NAME).elf

vpath %.c ../
vpath %.s ../
vpath %.S ../

# All Target
all: $(SUB_DIRS) $(OUTPUT_FILE_PATH)

# Linker target

$(OUTPUT_FILE_PATH): $(OBJS)
	@echo Building target: $@
	@echo Invoking: ARMCC Linker
	$(QUOTE)armlink$(QUOTE) --ro-base 0x00000000 --entry 0x00000000 --rw-base 0x20000000 --entry Reset_Handler --first __Vectors \
--strict --summary_stderr --info summarysizes --map --xref --callgraph --symbols \
--info sizes --info totals --info unused --info veneers --list $(OUTPUT_FILE_NAME).map \
-o $(OUTPUT_FILE_NAME).elf --cpu Cortex-M7.fp.dp \
$(OBJS_AS_ARGS)

	@echo Finished building target: $@

# Compiler target(s)




%.o: %.c
	@echo Building file: $<
	@echo ARMCC Compiler
	$(QUOTE)armcc$(QUOTE) --c99 -c -DDEBUG -O1 -g --apcs=interwork --split_sections --cpu Cortex-M7.fp.dp -D__SAME70Q21B__ \
-I"../" -I"../config" -I"../examples" -I"../hal/include" -I"../hal/utils/include" -I"../hpl/core" -I"../hpl/pio" -I"../hpl/pmc" -I"../hpl/tc" -I"../hpl/xdmac" -I"../hri" -I"../" -I"../CMSIS/Core/Include" -I"../same70b/include"  \
--depend "$@"  -o "$@" "$<"

	@echo Finished building: $<

%.o: %.s
	@echo Building file: $<
	@echo ARMCC Assembler
	$(QUOTE)armasm$(QUOTE) -g --apcs=interwork --cpu Cortex-M7.fp.dp --pd "D__SAME70Q21B__ SETA 1" \
-I"../" -I"../config" -I"../examples" -I"../hal/include" -I"../hal/utils/include" -I"../hpl/core" -I"../hpl/pio" -I"../hpl/pmc" -I"../hpl/tc" -I"../hpl/xdmac" -I"../hri" -I"../" -I"../CMSIS/Core/Include" -I"../same70b/include"  \
--depend "$(@:%.o=%.d)" -o "$@" "$<"

	@echo Finished building: $<

%.o: %.S
	@echo Building file: $<
	@echo ARMCC Preprocessing Assembler
	$(QUOTE)armcc$(QUOTE) --c99 -c -DDEBUG -O1 -g --apcs=interwork --split_sections --cpu Cortex-M7.fp.dp -D__SAME70Q21B__ \
-I"../" -I"../config" -I"../examples" -I"../hal/include" -I"../hal/utils/include" -I"../hpl/core" -I"../hpl/pio" -I"../hpl/pmc" -I"../hpl/tc" -I"../hpl/xdmac" -I"../hri" -I"../" -I"../CMSIS/Core/Include" -I"../same70b/include"  \
--depend "$@"  -o "$@" "$<"

	@echo Finished building: $<

# Detect changes in the dependent files and recompile the respective object files.
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(DEPS)),)
-include $(DEPS)
endif
endif

$(SUB_DIRS):
	$(MK_DIR) "$@"

clean:
	rm -f $(OBJS_AS_ARGS)
	rm -f $(OUTPUT_FILE_PATH)
	rm -f $(DEPS_AS_ARGS)
	rm -f $(OUTPUT_FILE_NAME).map $(OUTPUT_FILE_NAME).elf
