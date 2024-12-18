CC = gcc
CFLAGS = -Wall -g -Iinclude/
SRC = src/main.c src/tasks.c tests/test.c
OBJ = main test
TARGET = main

all: $(TARGET) test

$(TARGET): src/main.c src/tasks.c
	$(CC) $(CFLAGS) -o $(TARGET) src/main.c src/tasks.c

test: tests/test.c src/tasks.c
	$(CC) $(CFLAGS) -o test tests/test.c src/tasks.c
	./test

clean:
	rm -f $(TARGET) test
