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
ifeq "$(wildcard nbproject/Makefile-local-release.mk)" "nbproject/Makefile-local-release.mk"
include nbproject/Makefile-local-release.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=release
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/amsat-dl-upc.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/amsat-dl-upc.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
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
SOURCEFILES_QUOTED_IF_SPACED=src/driver/adf4351.c src/driver/usart.c src/driver/irq.c src/driver/kty82.c src/driver/adc.c src/downconv_data.c src/main.c src/pinmap.c src/alarm.c src/power.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/driver/adf4351.p1 ${OBJECTDIR}/src/driver/usart.p1 ${OBJECTDIR}/src/driver/irq.p1 ${OBJECTDIR}/src/driver/kty82.p1 ${OBJECTDIR}/src/driver/adc.p1 ${OBJECTDIR}/src/downconv_data.p1 ${OBJECTDIR}/src/main.p1 ${OBJECTDIR}/src/pinmap.p1 ${OBJECTDIR}/src/alarm.p1 ${OBJECTDIR}/src/power.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/src/driver/adf4351.p1.d ${OBJECTDIR}/src/driver/usart.p1.d ${OBJECTDIR}/src/driver/irq.p1.d ${OBJECTDIR}/src/driver/kty82.p1.d ${OBJECTDIR}/src/driver/adc.p1.d ${OBJECTDIR}/src/downconv_data.p1.d ${OBJECTDIR}/src/main.p1.d ${OBJECTDIR}/src/pinmap.p1.d ${OBJECTDIR}/src/alarm.p1.d ${OBJECTDIR}/src/power.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/driver/adf4351.p1 ${OBJECTDIR}/src/driver/usart.p1 ${OBJECTDIR}/src/driver/irq.p1 ${OBJECTDIR}/src/driver/kty82.p1 ${OBJECTDIR}/src/driver/adc.p1 ${OBJECTDIR}/src/downconv_data.p1 ${OBJECTDIR}/src/main.p1 ${OBJECTDIR}/src/pinmap.p1 ${OBJECTDIR}/src/alarm.p1 ${OBJECTDIR}/src/power.p1

# Source Files
SOURCEFILES=src/driver/adf4351.c src/driver/usart.c src/driver/irq.c src/driver/kty82.c src/driver/adc.c src/downconv_data.c src/main.c src/pinmap.c src/alarm.c src/power.c



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
	${MAKE}  -f nbproject/Makefile-release.mk dist/${CND_CONF}/${IMAGE_TYPE}/amsat-dl-upc.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F2520
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/driver/adf4351.p1: src/driver/adf4351.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver" 
	@${RM} ${OBJECTDIR}/src/driver/adf4351.p1.d 
	@${RM} ${OBJECTDIR}/src/driver/adf4351.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/driver/adf4351.p1 src/driver/adf4351.c 
	@-${MV} ${OBJECTDIR}/src/driver/adf4351.d ${OBJECTDIR}/src/driver/adf4351.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/driver/adf4351.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/driver/usart.p1: src/driver/usart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver" 
	@${RM} ${OBJECTDIR}/src/driver/usart.p1.d 
	@${RM} ${OBJECTDIR}/src/driver/usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/driver/usart.p1 src/driver/usart.c 
	@-${MV} ${OBJECTDIR}/src/driver/usart.d ${OBJECTDIR}/src/driver/usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/driver/usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/driver/irq.p1: src/driver/irq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver" 
	@${RM} ${OBJECTDIR}/src/driver/irq.p1.d 
	@${RM} ${OBJECTDIR}/src/driver/irq.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/driver/irq.p1 src/driver/irq.c 
	@-${MV} ${OBJECTDIR}/src/driver/irq.d ${OBJECTDIR}/src/driver/irq.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/driver/irq.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/driver/kty82.p1: src/driver/kty82.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver" 
	@${RM} ${OBJECTDIR}/src/driver/kty82.p1.d 
	@${RM} ${OBJECTDIR}/src/driver/kty82.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/driver/kty82.p1 src/driver/kty82.c 
	@-${MV} ${OBJECTDIR}/src/driver/kty82.d ${OBJECTDIR}/src/driver/kty82.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/driver/kty82.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/driver/adc.p1: src/driver/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver" 
	@${RM} ${OBJECTDIR}/src/driver/adc.p1.d 
	@${RM} ${OBJECTDIR}/src/driver/adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/driver/adc.p1 src/driver/adc.c 
	@-${MV} ${OBJECTDIR}/src/driver/adc.d ${OBJECTDIR}/src/driver/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/driver/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/downconv_data.p1: src/downconv_data.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/downconv_data.p1.d 
	@${RM} ${OBJECTDIR}/src/downconv_data.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/downconv_data.p1 src/downconv_data.c 
	@-${MV} ${OBJECTDIR}/src/downconv_data.d ${OBJECTDIR}/src/downconv_data.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/downconv_data.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/main.p1: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.p1.d 
	@${RM} ${OBJECTDIR}/src/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/main.p1 src/main.c 
	@-${MV} ${OBJECTDIR}/src/main.d ${OBJECTDIR}/src/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/pinmap.p1: src/pinmap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pinmap.p1.d 
	@${RM} ${OBJECTDIR}/src/pinmap.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/pinmap.p1 src/pinmap.c 
	@-${MV} ${OBJECTDIR}/src/pinmap.d ${OBJECTDIR}/src/pinmap.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/pinmap.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/alarm.p1: src/alarm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/alarm.p1.d 
	@${RM} ${OBJECTDIR}/src/alarm.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/alarm.p1 src/alarm.c 
	@-${MV} ${OBJECTDIR}/src/alarm.d ${OBJECTDIR}/src/alarm.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/alarm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/power.p1: src/power.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/power.p1.d 
	@${RM} ${OBJECTDIR}/src/power.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/power.p1 src/power.c 
	@-${MV} ${OBJECTDIR}/src/power.d ${OBJECTDIR}/src/power.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/power.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/src/driver/adf4351.p1: src/driver/adf4351.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver" 
	@${RM} ${OBJECTDIR}/src/driver/adf4351.p1.d 
	@${RM} ${OBJECTDIR}/src/driver/adf4351.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/driver/adf4351.p1 src/driver/adf4351.c 
	@-${MV} ${OBJECTDIR}/src/driver/adf4351.d ${OBJECTDIR}/src/driver/adf4351.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/driver/adf4351.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/driver/usart.p1: src/driver/usart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver" 
	@${RM} ${OBJECTDIR}/src/driver/usart.p1.d 
	@${RM} ${OBJECTDIR}/src/driver/usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/driver/usart.p1 src/driver/usart.c 
	@-${MV} ${OBJECTDIR}/src/driver/usart.d ${OBJECTDIR}/src/driver/usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/driver/usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/driver/irq.p1: src/driver/irq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver" 
	@${RM} ${OBJECTDIR}/src/driver/irq.p1.d 
	@${RM} ${OBJECTDIR}/src/driver/irq.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/driver/irq.p1 src/driver/irq.c 
	@-${MV} ${OBJECTDIR}/src/driver/irq.d ${OBJECTDIR}/src/driver/irq.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/driver/irq.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/driver/kty82.p1: src/driver/kty82.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver" 
	@${RM} ${OBJECTDIR}/src/driver/kty82.p1.d 
	@${RM} ${OBJECTDIR}/src/driver/kty82.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/driver/kty82.p1 src/driver/kty82.c 
	@-${MV} ${OBJECTDIR}/src/driver/kty82.d ${OBJECTDIR}/src/driver/kty82.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/driver/kty82.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/driver/adc.p1: src/driver/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver" 
	@${RM} ${OBJECTDIR}/src/driver/adc.p1.d 
	@${RM} ${OBJECTDIR}/src/driver/adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/driver/adc.p1 src/driver/adc.c 
	@-${MV} ${OBJECTDIR}/src/driver/adc.d ${OBJECTDIR}/src/driver/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/driver/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/downconv_data.p1: src/downconv_data.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/downconv_data.p1.d 
	@${RM} ${OBJECTDIR}/src/downconv_data.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/downconv_data.p1 src/downconv_data.c 
	@-${MV} ${OBJECTDIR}/src/downconv_data.d ${OBJECTDIR}/src/downconv_data.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/downconv_data.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/main.p1: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.p1.d 
	@${RM} ${OBJECTDIR}/src/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/main.p1 src/main.c 
	@-${MV} ${OBJECTDIR}/src/main.d ${OBJECTDIR}/src/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/pinmap.p1: src/pinmap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pinmap.p1.d 
	@${RM} ${OBJECTDIR}/src/pinmap.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/pinmap.p1 src/pinmap.c 
	@-${MV} ${OBJECTDIR}/src/pinmap.d ${OBJECTDIR}/src/pinmap.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/pinmap.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/alarm.p1: src/alarm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/alarm.p1.d 
	@${RM} ${OBJECTDIR}/src/alarm.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/alarm.p1 src/alarm.c 
	@-${MV} ${OBJECTDIR}/src/alarm.d ${OBJECTDIR}/src/alarm.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/alarm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/power.p1: src/power.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/power.p1.d 
	@${RM} ${OBJECTDIR}/src/power.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -DXPRJ_release=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/power.p1 src/power.c 
	@-${MV} ${OBJECTDIR}/src/power.d ${OBJECTDIR}/src/power.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/power.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

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
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/amsat-dl-upc.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/amsat-dl-upc.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_release=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -mrom=default,-7dc0-7fff -mram=default,-5f4-5ff,-f9c-f9c,-fd4-fd4,-fdb-fdf,-fe3-fe7,-feb-fef,-ffd-fff  $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/amsat-dl-upc.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/amsat-dl-upc.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/amsat-dl-upc.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/amsat-dl-upc.${IMAGE_TYPE}.map  -DXPRJ_release=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -D__RELEASE__ -xassembler-with-cpp -I"src" -v -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/amsat-dl-upc.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/release
	${RM} -r dist/release

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
