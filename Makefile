# =========================
# Compiler
# =========================
CC = gcc

# =========================
# Project folders
# =========================
SRC_DIR = course1/src
INC_DIR = course1

# =========================
# Flags
# =========================
CFLAGS = -Wall -Werror -g -O0 -std=c99 \
         -DCOURSE1 -DVERBOSE -DHOST \
         -Icourse1/include \
         -Iassessments/m2/include/common \
         -Iassessments/m2/include/CMSIS \
         -Iassessments/m2/include/msp432
# =========================
# Sources
# =========================
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/memory.c \
       $(SRC_DIR)/data.c \
       $(SRC_DIR)/stats.c \
       $(SRC_DIR)/course1.c

# Objects
OBJS = main.o memory.o data.o stats.o course1.o

# Output
TARGET = course1.out

# =========================
# Build
# =========================
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(TARGET)

main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@

memory.o: $(SRC_DIR)/memory.c
	$(CC) $(CFLAGS) -c $< -o $@

data.o: $(SRC_DIR)/data.c
	$(CC) $(CFLAGS) -c $< -o $@

stats.o: $(SRC_DIR)/stats.c
	$(CC) $(CFLAGS) -c $< -o $@

course1.o: $(SRC_DIR)/course1.c
	$(CC) $(CFLAGS) -c $< -o $@

# =========================
# Clean
# =========================
clean:
	rm -f *.o *.out *.map *.asm *.i
