TARGET = main.exe
SRCS = main.c board.c food.c snake.c

CC = gcc
CFLAGS = -Wall -g

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)
run: all
	./$(TARGET)
clean:
	rm -f $(TARGET)
