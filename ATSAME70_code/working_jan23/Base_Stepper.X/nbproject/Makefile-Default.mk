#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-Default.mk)" "nbproject/Makefile-local-Default.mk"
include nbproject/Makefile-local-Default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=Default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Base_Stepper.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Base_Stepper.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=examples/driver_examples.c hal/src/hal_atomic.c hal/src/hal_delay.c hal/src/hal_gpio.c hal/src/hal_init.c hal/src/hal_io.c hal/src/hal_sleep.c hal/utils/src/utils_assert.c hal/utils/src/utils_event.c hal/utils/src/utils_list.c hal/utils/src/utils_syscalls.c hpl/core/hpl_core_m7_base.c hpl/core/hpl_init.c hpl/pmc/hpl_pmc.c hpl/pmc/hpl_sleep.c hpl/xdmac/hpl_xdmac.c same70b/gcc/gcc/startup_same70q21b.c same70b/gcc/system_same70q21b.c led_flasher_main.c driver_init.c atmel_start.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/examples/driver_examples.o ${OBJECTDIR}/hal/src/hal_atomic.o ${OBJECTDIR}/hal/src/hal_delay.o ${OBJECTDIR}/hal/src/hal_gpio.o ${OBJECTDIR}/hal/src/hal_init.o ${OBJECTDIR}/hal/src/hal_io.o ${OBJECTDIR}/hal/src/hal_sleep.o ${OBJECTDIR}/hal/utils/src/utils_assert.o ${OBJECTDIR}/hal/utils/src/utils_event.o ${OBJECTDIR}/hal/utils/src/utils_list.o ${OBJECTDIR}/hal/utils/src/utils_syscalls.o ${OBJECTDIR}/hpl/core/hpl_core_m7_base.o ${OBJECTDIR}/hpl/core/hpl_init.o ${OBJECTDIR}/hpl/pmc/hpl_pmc.o ${OBJECTDIR}/hpl/pmc/hpl_sleep.o ${OBJECTDIR}/hpl/xdmac/hpl_xdmac.o ${OBJECTDIR}/same70b/gcc/gcc/startup_same70q21b.o ${OBJECTDIR}/same70b/gcc/system_same70q21b.o ${OBJECTDIR}/led_flasher_main.o ${OBJECTDIR}/driver_init.o ${OBJECTDIR}/atmel_start.o
POSSIBLE_DEPFILES=${OBJECTDIR}/examples/driver_examples.o.d ${OBJECTDIR}/hal/src/hal_atomic.o.d ${OBJECTDIR}/hal/src/hal_delay.o.d ${OBJECTDIR}/hal/src/hal_gpio.o.d ${OBJECTDIR}/hal/src/hal_init.o.d ${OBJECTDIR}/hal/src/hal_io.o.d ${OBJECTDIR}/hal/src/hal_sleep.o.d ${OBJECTDIR}/hal/utils/src/utils_assert.o.d ${OBJECTDIR}/hal/utils/src/utils_event.o.d ${OBJECTDIR}/hal/utils/src/utils_list.o.d ${OBJECTDIR}/hal/utils/src/utils_syscalls.o.d ${OBJECTDIR}/hpl/core/hpl_core_m7_base.o.d ${OBJECTDIR}/hpl/core/hpl_init.o.d ${OBJECTDIR}/hpl/pmc/hpl_pmc.o.d ${OBJECTDIR}/hpl/pmc/hpl_sleep.o.d ${OBJECTDIR}/hpl/xdmac/hpl_xdmac.o.d ${OBJECTDIR}/same70b/gcc/gcc/startup_same70q21b.o.d ${OBJECTDIR}/same70b/gcc/system_same70q21b.o.d ${OBJECTDIR}/led_flasher_main.o.d ${OBJECTDIR}/driver_init.o.d ${OBJECTDIR}/atmel_start.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/examples/driver_examples.o ${OBJECTDIR}/hal/src/hal_atomic.o ${OBJECTDIR}/hal/src/hal_delay.o ${OBJECTDIR}/hal/src/hal_gpio.o ${OBJECTDIR}/hal/src/hal_init.o ${OBJECTDIR}/hal/src/hal_io.o ${OBJECTDIR}/hal/src/hal_sleep.o ${OBJECTDIR}/hal/utils/src/utils_assert.o ${OBJECTDIR}/hal/utils/src/utils_event.o ${OBJECTDIR}/hal/utils/src/utils_list.o ${OBJECTDIR}/hal/utils/src/utils_syscalls.o ${OBJECTDIR}/hpl/core/hpl_core_m7_base.o ${OBJECTDIR}/hpl/core/hpl_init.o ${OBJECTDIR}/hpl/pmc/hpl_pmc.o ${OBJECTDIR}/hpl/pmc/hpl_sleep.o ${OBJECTDIR}/hpl/xdmac/hpl_xdmac.o ${OBJECTDIR}/same70b/gcc/gcc/startup_same70q21b.o ${OBJECTDIR}/same70b/gcc/system_same70q21b.o ${OBJECTDIR}/led_flasher_main.o ${OBJECTDIR}/driver_init.o ${OBJECTDIR}/atmel_start.o

# Source Files
SOURCEFILES=examples/driver_examples.c hal/src/hal_atomic.c hal/src/hal_delay.c hal/src/hal_gpio.c hal/src/hal_init.c hal/src/hal_io.c hal/src/hal_sleep.c hal/utils/src/utils_assert.c hal/utils/src/utils_event.c hal/utils/src/utils_list.c hal/utils/src/utils_syscalls.c hpl/core/hpl_core_m7_base.c hpl/core/hpl_init.c hpl/pmc/hpl_pmc.c hpl/pmc/hpl_sleep.c hpl/xdmac/hpl_xdmac.c same70b/gcc/gcc/startup_same70q21b.c same70b/gcc/system_same70q21b.c led_flasher_main.c driver_init.c atmel_start.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-Default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Base_Stepper.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=SAME70Q21B
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/examples/driver_examples.o: examples/driver_examples.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/examples" 
	@${RM} ${OBJECTDIR}/examples/driver_examples.o.d 
	@${RM} ${OBJECTDIR}/examples/driver_examples.o 
	@${FIXDEPS} "${OBJECTDIR}/examples/driver_examples.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/examples/driver_examples.o.d" -o ${OBJECTDIR}/examples/driver_examples.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/examples/driver_examples.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/src/hal_atomic.o: hal/src/hal_atomic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/src" 
	@${RM} ${OBJECTDIR}/hal/src/hal_atomic.o.d 
	@${RM} ${OBJECTDIR}/hal/src/hal_atomic.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/src/hal_atomic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/src/hal_atomic.o.d" -o ${OBJECTDIR}/hal/src/hal_atomic.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/src/hal_atomic.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/src/hal_delay.o: hal/src/hal_delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/src" 
	@${RM} ${OBJECTDIR}/hal/src/hal_delay.o.d 
	@${RM} ${OBJECTDIR}/hal/src/hal_delay.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/src/hal_delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/src/hal_delay.o.d" -o ${OBJECTDIR}/hal/src/hal_delay.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/src/hal_delay.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/src/hal_gpio.o: hal/src/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/src" 
	@${RM} ${OBJECTDIR}/hal/src/hal_gpio.o.d 
	@${RM} ${OBJECTDIR}/hal/src/hal_gpio.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/src/hal_gpio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/src/hal_gpio.o.d" -o ${OBJECTDIR}/hal/src/hal_gpio.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/src/hal_gpio.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/src/hal_init.o: hal/src/hal_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/src" 
	@${RM} ${OBJECTDIR}/hal/src/hal_init.o.d 
	@${RM} ${OBJECTDIR}/hal/src/hal_init.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/src/hal_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/src/hal_init.o.d" -o ${OBJECTDIR}/hal/src/hal_init.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/src/hal_init.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/src/hal_io.o: hal/src/hal_io.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/src" 
	@${RM} ${OBJECTDIR}/hal/src/hal_io.o.d 
	@${RM} ${OBJECTDIR}/hal/src/hal_io.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/src/hal_io.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/src/hal_io.o.d" -o ${OBJECTDIR}/hal/src/hal_io.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/src/hal_io.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/src/hal_sleep.o: hal/src/hal_sleep.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/src" 
	@${RM} ${OBJECTDIR}/hal/src/hal_sleep.o.d 
	@${RM} ${OBJECTDIR}/hal/src/hal_sleep.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/src/hal_sleep.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/src/hal_sleep.o.d" -o ${OBJECTDIR}/hal/src/hal_sleep.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/src/hal_sleep.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/utils/src/utils_assert.o: hal/utils/src/utils_assert.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/utils/src" 
	@${RM} ${OBJECTDIR}/hal/utils/src/utils_assert.o.d 
	@${RM} ${OBJECTDIR}/hal/utils/src/utils_assert.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/utils/src/utils_assert.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/utils/src/utils_assert.o.d" -o ${OBJECTDIR}/hal/utils/src/utils_assert.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/utils/src/utils_assert.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/utils/src/utils_event.o: hal/utils/src/utils_event.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/utils/src" 
	@${RM} ${OBJECTDIR}/hal/utils/src/utils_event.o.d 
	@${RM} ${OBJECTDIR}/hal/utils/src/utils_event.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/utils/src/utils_event.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/utils/src/utils_event.o.d" -o ${OBJECTDIR}/hal/utils/src/utils_event.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/utils/src/utils_event.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/utils/src/utils_list.o: hal/utils/src/utils_list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/utils/src" 
	@${RM} ${OBJECTDIR}/hal/utils/src/utils_list.o.d 
	@${RM} ${OBJECTDIR}/hal/utils/src/utils_list.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/utils/src/utils_list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/utils/src/utils_list.o.d" -o ${OBJECTDIR}/hal/utils/src/utils_list.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/utils/src/utils_list.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/utils/src/utils_syscalls.o: hal/utils/src/utils_syscalls.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/utils/src" 
	@${RM} ${OBJECTDIR}/hal/utils/src/utils_syscalls.o.d 
	@${RM} ${OBJECTDIR}/hal/utils/src/utils_syscalls.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/utils/src/utils_syscalls.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/utils/src/utils_syscalls.o.d" -o ${OBJECTDIR}/hal/utils/src/utils_syscalls.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/utils/src/utils_syscalls.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hpl/core/hpl_core_m7_base.o: hpl/core/hpl_core_m7_base.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hpl/core" 
	@${RM} ${OBJECTDIR}/hpl/core/hpl_core_m7_base.o.d 
	@${RM} ${OBJECTDIR}/hpl/core/hpl_core_m7_base.o 
	@${FIXDEPS} "${OBJECTDIR}/hpl/core/hpl_core_m7_base.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hpl/core/hpl_core_m7_base.o.d" -o ${OBJECTDIR}/hpl/core/hpl_core_m7_base.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hpl/core/hpl_core_m7_base.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hpl/core/hpl_init.o: hpl/core/hpl_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hpl/core" 
	@${RM} ${OBJECTDIR}/hpl/core/hpl_init.o.d 
	@${RM} ${OBJECTDIR}/hpl/core/hpl_init.o 
	@${FIXDEPS} "${OBJECTDIR}/hpl/core/hpl_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hpl/core/hpl_init.o.d" -o ${OBJECTDIR}/hpl/core/hpl_init.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hpl/core/hpl_init.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hpl/pmc/hpl_pmc.o: hpl/pmc/hpl_pmc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hpl/pmc" 
	@${RM} ${OBJECTDIR}/hpl/pmc/hpl_pmc.o.d 
	@${RM} ${OBJECTDIR}/hpl/pmc/hpl_pmc.o 
	@${FIXDEPS} "${OBJECTDIR}/hpl/pmc/hpl_pmc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hpl/pmc/hpl_pmc.o.d" -o ${OBJECTDIR}/hpl/pmc/hpl_pmc.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hpl/pmc/hpl_pmc.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hpl/pmc/hpl_sleep.o: hpl/pmc/hpl_sleep.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hpl/pmc" 
	@${RM} ${OBJECTDIR}/hpl/pmc/hpl_sleep.o.d 
	@${RM} ${OBJECTDIR}/hpl/pmc/hpl_sleep.o 
	@${FIXDEPS} "${OBJECTDIR}/hpl/pmc/hpl_sleep.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hpl/pmc/hpl_sleep.o.d" -o ${OBJECTDIR}/hpl/pmc/hpl_sleep.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hpl/pmc/hpl_sleep.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hpl/xdmac/hpl_xdmac.o: hpl/xdmac/hpl_xdmac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hpl/xdmac" 
	@${RM} ${OBJECTDIR}/hpl/xdmac/hpl_xdmac.o.d 
	@${RM} ${OBJECTDIR}/hpl/xdmac/hpl_xdmac.o 
	@${FIXDEPS} "${OBJECTDIR}/hpl/xdmac/hpl_xdmac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hpl/xdmac/hpl_xdmac.o.d" -o ${OBJECTDIR}/hpl/xdmac/hpl_xdmac.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hpl/xdmac/hpl_xdmac.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/same70b/gcc/gcc/startup_same70q21b.o: same70b/gcc/gcc/startup_same70q21b.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/same70b/gcc/gcc" 
	@${RM} ${OBJECTDIR}/same70b/gcc/gcc/startup_same70q21b.o.d 
	@${RM} ${OBJECTDIR}/same70b/gcc/gcc/startup_same70q21b.o 
	@${FIXDEPS} "${OBJECTDIR}/same70b/gcc/gcc/startup_same70q21b.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/same70b/gcc/gcc/startup_same70q21b.o.d" -o ${OBJECTDIR}/same70b/gcc/gcc/startup_same70q21b.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/same70b/gcc/gcc/startup_same70q21b.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/same70b/gcc/system_same70q21b.o: same70b/gcc/system_same70q21b.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/same70b/gcc" 
	@${RM} ${OBJECTDIR}/same70b/gcc/system_same70q21b.o.d 
	@${RM} ${OBJECTDIR}/same70b/gcc/system_same70q21b.o 
	@${FIXDEPS} "${OBJECTDIR}/same70b/gcc/system_same70q21b.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/same70b/gcc/system_same70q21b.o.d" -o ${OBJECTDIR}/same70b/gcc/system_same70q21b.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/same70b/gcc/system_same70q21b.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/led_flasher_main.o: led_flasher_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/led_flasher_main.o.d 
	@${RM} ${OBJECTDIR}/led_flasher_main.o 
	@${FIXDEPS} "${OBJECTDIR}/led_flasher_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/led_flasher_main.o.d" -o ${OBJECTDIR}/led_flasher_main.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/led_flasher_main.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/driver_init.o: driver_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/driver_init.o.d 
	@${RM} ${OBJECTDIR}/driver_init.o 
	@${FIXDEPS} "${OBJECTDIR}/driver_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/driver_init.o.d" -o ${OBJECTDIR}/driver_init.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/driver_init.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/atmel_start.o: atmel_start.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/atmel_start.o.d 
	@${RM} ${OBJECTDIR}/atmel_start.o 
	@${FIXDEPS} "${OBJECTDIR}/atmel_start.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/atmel_start.o.d" -o ${OBJECTDIR}/atmel_start.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/atmel_start.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/examples/driver_examples.o: examples/driver_examples.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/examples" 
	@${RM} ${OBJECTDIR}/examples/driver_examples.o.d 
	@${RM} ${OBJECTDIR}/examples/driver_examples.o 
	@${FIXDEPS} "${OBJECTDIR}/examples/driver_examples.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/examples/driver_examples.o.d" -o ${OBJECTDIR}/examples/driver_examples.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/examples/driver_examples.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/src/hal_atomic.o: hal/src/hal_atomic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/src" 
	@${RM} ${OBJECTDIR}/hal/src/hal_atomic.o.d 
	@${RM} ${OBJECTDIR}/hal/src/hal_atomic.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/src/hal_atomic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/src/hal_atomic.o.d" -o ${OBJECTDIR}/hal/src/hal_atomic.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/src/hal_atomic.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/src/hal_delay.o: hal/src/hal_delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/src" 
	@${RM} ${OBJECTDIR}/hal/src/hal_delay.o.d 
	@${RM} ${OBJECTDIR}/hal/src/hal_delay.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/src/hal_delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/src/hal_delay.o.d" -o ${OBJECTDIR}/hal/src/hal_delay.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/src/hal_delay.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/src/hal_gpio.o: hal/src/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/src" 
	@${RM} ${OBJECTDIR}/hal/src/hal_gpio.o.d 
	@${RM} ${OBJECTDIR}/hal/src/hal_gpio.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/src/hal_gpio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/src/hal_gpio.o.d" -o ${OBJECTDIR}/hal/src/hal_gpio.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/src/hal_gpio.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/src/hal_init.o: hal/src/hal_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/src" 
	@${RM} ${OBJECTDIR}/hal/src/hal_init.o.d 
	@${RM} ${OBJECTDIR}/hal/src/hal_init.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/src/hal_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/src/hal_init.o.d" -o ${OBJECTDIR}/hal/src/hal_init.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/src/hal_init.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/src/hal_io.o: hal/src/hal_io.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/src" 
	@${RM} ${OBJECTDIR}/hal/src/hal_io.o.d 
	@${RM} ${OBJECTDIR}/hal/src/hal_io.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/src/hal_io.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/src/hal_io.o.d" -o ${OBJECTDIR}/hal/src/hal_io.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/src/hal_io.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/src/hal_sleep.o: hal/src/hal_sleep.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/src" 
	@${RM} ${OBJECTDIR}/hal/src/hal_sleep.o.d 
	@${RM} ${OBJECTDIR}/hal/src/hal_sleep.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/src/hal_sleep.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/src/hal_sleep.o.d" -o ${OBJECTDIR}/hal/src/hal_sleep.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/src/hal_sleep.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/utils/src/utils_assert.o: hal/utils/src/utils_assert.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/utils/src" 
	@${RM} ${OBJECTDIR}/hal/utils/src/utils_assert.o.d 
	@${RM} ${OBJECTDIR}/hal/utils/src/utils_assert.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/utils/src/utils_assert.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/utils/src/utils_assert.o.d" -o ${OBJECTDIR}/hal/utils/src/utils_assert.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/utils/src/utils_assert.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/utils/src/utils_event.o: hal/utils/src/utils_event.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/utils/src" 
	@${RM} ${OBJECTDIR}/hal/utils/src/utils_event.o.d 
	@${RM} ${OBJECTDIR}/hal/utils/src/utils_event.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/utils/src/utils_event.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/utils/src/utils_event.o.d" -o ${OBJECTDIR}/hal/utils/src/utils_event.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/utils/src/utils_event.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/utils/src/utils_list.o: hal/utils/src/utils_list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/utils/src" 
	@${RM} ${OBJECTDIR}/hal/utils/src/utils_list.o.d 
	@${RM} ${OBJECTDIR}/hal/utils/src/utils_list.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/utils/src/utils_list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/utils/src/utils_list.o.d" -o ${OBJECTDIR}/hal/utils/src/utils_list.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/utils/src/utils_list.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal/utils/src/utils_syscalls.o: hal/utils/src/utils_syscalls.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hal/utils/src" 
	@${RM} ${OBJECTDIR}/hal/utils/src/utils_syscalls.o.d 
	@${RM} ${OBJECTDIR}/hal/utils/src/utils_syscalls.o 
	@${FIXDEPS} "${OBJECTDIR}/hal/utils/src/utils_syscalls.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hal/utils/src/utils_syscalls.o.d" -o ${OBJECTDIR}/hal/utils/src/utils_syscalls.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hal/utils/src/utils_syscalls.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hpl/core/hpl_core_m7_base.o: hpl/core/hpl_core_m7_base.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hpl/core" 
	@${RM} ${OBJECTDIR}/hpl/core/hpl_core_m7_base.o.d 
	@${RM} ${OBJECTDIR}/hpl/core/hpl_core_m7_base.o 
	@${FIXDEPS} "${OBJECTDIR}/hpl/core/hpl_core_m7_base.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hpl/core/hpl_core_m7_base.o.d" -o ${OBJECTDIR}/hpl/core/hpl_core_m7_base.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hpl/core/hpl_core_m7_base.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hpl/core/hpl_init.o: hpl/core/hpl_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hpl/core" 
	@${RM} ${OBJECTDIR}/hpl/core/hpl_init.o.d 
	@${RM} ${OBJECTDIR}/hpl/core/hpl_init.o 
	@${FIXDEPS} "${OBJECTDIR}/hpl/core/hpl_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hpl/core/hpl_init.o.d" -o ${OBJECTDIR}/hpl/core/hpl_init.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hpl/core/hpl_init.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hpl/pmc/hpl_pmc.o: hpl/pmc/hpl_pmc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hpl/pmc" 
	@${RM} ${OBJECTDIR}/hpl/pmc/hpl_pmc.o.d 
	@${RM} ${OBJECTDIR}/hpl/pmc/hpl_pmc.o 
	@${FIXDEPS} "${OBJECTDIR}/hpl/pmc/hpl_pmc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hpl/pmc/hpl_pmc.o.d" -o ${OBJECTDIR}/hpl/pmc/hpl_pmc.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hpl/pmc/hpl_pmc.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hpl/pmc/hpl_sleep.o: hpl/pmc/hpl_sleep.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hpl/pmc" 
	@${RM} ${OBJECTDIR}/hpl/pmc/hpl_sleep.o.d 
	@${RM} ${OBJECTDIR}/hpl/pmc/hpl_sleep.o 
	@${FIXDEPS} "${OBJECTDIR}/hpl/pmc/hpl_sleep.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hpl/pmc/hpl_sleep.o.d" -o ${OBJECTDIR}/hpl/pmc/hpl_sleep.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hpl/pmc/hpl_sleep.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hpl/xdmac/hpl_xdmac.o: hpl/xdmac/hpl_xdmac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/hpl/xdmac" 
	@${RM} ${OBJECTDIR}/hpl/xdmac/hpl_xdmac.o.d 
	@${RM} ${OBJECTDIR}/hpl/xdmac/hpl_xdmac.o 
	@${FIXDEPS} "${OBJECTDIR}/hpl/xdmac/hpl_xdmac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/hpl/xdmac/hpl_xdmac.o.d" -o ${OBJECTDIR}/hpl/xdmac/hpl_xdmac.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/hpl/xdmac/hpl_xdmac.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/same70b/gcc/gcc/startup_same70q21b.o: same70b/gcc/gcc/startup_same70q21b.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/same70b/gcc/gcc" 
	@${RM} ${OBJECTDIR}/same70b/gcc/gcc/startup_same70q21b.o.d 
	@${RM} ${OBJECTDIR}/same70b/gcc/gcc/startup_same70q21b.o 
	@${FIXDEPS} "${OBJECTDIR}/same70b/gcc/gcc/startup_same70q21b.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/same70b/gcc/gcc/startup_same70q21b.o.d" -o ${OBJECTDIR}/same70b/gcc/gcc/startup_same70q21b.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/same70b/gcc/gcc/startup_same70q21b.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/same70b/gcc/system_same70q21b.o: same70b/gcc/system_same70q21b.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/same70b/gcc" 
	@${RM} ${OBJECTDIR}/same70b/gcc/system_same70q21b.o.d 
	@${RM} ${OBJECTDIR}/same70b/gcc/system_same70q21b.o 
	@${FIXDEPS} "${OBJECTDIR}/same70b/gcc/system_same70q21b.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/same70b/gcc/system_same70q21b.o.d" -o ${OBJECTDIR}/same70b/gcc/system_same70q21b.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/same70b/gcc/system_same70q21b.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/led_flasher_main.o: led_flasher_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/led_flasher_main.o.d 
	@${RM} ${OBJECTDIR}/led_flasher_main.o 
	@${FIXDEPS} "${OBJECTDIR}/led_flasher_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/led_flasher_main.o.d" -o ${OBJECTDIR}/led_flasher_main.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/led_flasher_main.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/driver_init.o: driver_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/driver_init.o.d 
	@${RM} ${OBJECTDIR}/driver_init.o 
	@${FIXDEPS} "${OBJECTDIR}/driver_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/driver_init.o.d" -o ${OBJECTDIR}/driver_init.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/driver_init.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/atmel_start.o: atmel_start.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/atmel_start.o.d 
	@${RM} ${OBJECTDIR}/atmel_start.o 
	@${FIXDEPS} "${OBJECTDIR}/atmel_start.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb -I "examples" -I "hpl/pio" -I "hpl/pmc" -I "hal/utils/include" -I "hal/include" -I "hpl/xdmac" -I "./." -I "config" -I "hpl/core" -I "hri"  -I "same70b/include" -I "CMSIS/Core/Include"  -Os -ffunction-sections -mlong-calls -Wall -MMD -MF "${OBJECTDIR}/atmel_start.o.d" -o ${OBJECTDIR}/atmel_start.o "/home/al/Documents/Year5Sem1/ELE700/projects/actual_cnc_stuff/Base_Stepper.X/atmel_start.c"  -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Base_Stepper.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=cortex-m7   -gdwarf-2  -D__$(MP_PROCESSOR_OPTION)__    -mthumb --specs=nosys.specs -Wl,-Map="dist/${CND_CONF}/${IMAGE_TYPE}/Base_Stepper.X.${IMAGE_TYPE}.map"  -o dist/${CND_CONF}/${IMAGE_TYPE}/Base_Stepper.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1  -L"same70b/gcc/gcc" -Wl,--gc-sections   -T"same70b/gcc/gcc/same70q21b_flash.ld" 
	
	
	
	
	
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Base_Stepper.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=cortex-m7  -D__$(MP_PROCESSOR_OPTION)__    -mthumb --specs=nosys.specs -Wl,-Map="dist/${CND_CONF}/${IMAGE_TYPE}/Base_Stepper.X.${IMAGE_TYPE}.map"  -o dist/${CND_CONF}/${IMAGE_TYPE}/Base_Stepper.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_Default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)  -L"same70b/gcc/gcc" -Wl,--gc-sections   -T"same70b/gcc/gcc/same70q21b_flash.ld" 
	
	${MP_CC_DIR}/arm-none-eabi-objcopy -O ihex -R .eeprom -R .fuse -R .lock -R .signature "dist/${CND_CONF}/${IMAGE_TYPE}/Base_Stepper.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Base_Stepper.X.${IMAGE_TYPE}.hex"
	
	
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Default
	${RM} -r dist/Default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
