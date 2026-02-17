# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g -std=c11

# Directories
SRC_DIR = src
BUILD_DIR = build
MLIB_DIR = mlib

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# mlib object
MLIB_OBJ = $(BUILD_DIR)/mlib.o

# Output executable
TARGET = mt

# -----------------------
# Rules
# -----------------------

all: $(TARGET)

# Compile MCC
$(TARGET): $(OBJS) $(MLIB_OBJ)
	$(CC) $(CFLAGS) $(OBJS) $(MLIB_OBJ) -o $@

# Build object files for src/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build object file for mlib
$(BUILD_DIR)/mlib.o: $(MLIB_DIR)/mlib.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean

