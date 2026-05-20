#******************************************************************************
# Copyright (C) 2026 by Kerellos Emad
#*****************************************************************************

# Target source files for compile execution
SOURCES = \
	main.c \
	memory.c \
	data.c \
	course1.c \
	stats.c

# Include paths for preprocessor lookup aligned with your workspace
INCLUDES = \
	-I. \
	-I./course1 \
	-I../assessments/m2/include/common \
	-I../assessments/m2/include/CMSIS \
	-I../assessments/m2/include/msp432
