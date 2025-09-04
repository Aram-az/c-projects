# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g

# Source files
SRCS = main.c board.c snake.c food.c

# Object files
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = snake.exe

# Default target (what happens when you type "make")
all: $(TARGET)

# Link step: combine .o files into the final program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile each .c into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Shortcut to run
run: $(TARGET)
	./$(TARGET)