# Define variables
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror
TARGET = writer
SRC = writer.c
OBJ = $(SRC:.c=.o)

# Default target to build the writer application
all: $(TARGET)

# Rule to build the writer application
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove built files
clean:
	rm -f $(TARGET) $(OBJ)

# PHONY targets
.PHONY: all clean
