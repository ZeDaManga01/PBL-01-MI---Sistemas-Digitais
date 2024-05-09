# Compiler
CC = gcc

# Compiler flags
CFLAGS = -std=c99 -Wall -Wextra

# Source files
MAIN_SRC = main.c
TICTACTOE_SRC_DIR = tictactoe
MICE_SRC_DIR = mice

TICTACTOE_SRC = $(TICTACTOE_SRC_DIR)/tictactoe.c
MICE_SRC = $(MICE_SRC_DIR)/mice.c

# Object files
OBJ = $(MAIN_SRC:.c=.o) $(TICTACTOE_SRC:.c=.o) $(MICE_SRC:.c=.o)

# Header files
HEADERS = $(TICTACTOE_SRC_DIR)/tictactoe.h $(MICE_SRC_DIR)/mice.h

# Include directories
INCLUDE_DIRS = -I$(TICTACTOE_SRC_DIR) -I$(MICE_SRC_DIR)

# Executable name
TARGET = ttt

# Default rule
all: $(TARGET) clean

# Rule to build the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $@ $^ -lm

# Rule to compile source files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ)