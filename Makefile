
CC = gcc
CFLAGS = -Wall -I./include
LDFLAGS = -lm  

PW_DIRS = pw1

OBJ = main.o $(addprefix $(PW_DIRS)/, pw1.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)  

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

$(PW_DIRS)/pw1.o: $(PW_DIRS)/pw1.c $(PW_DIRS)/pw1.h
	$(CC) $(CFLAGS) -c $(PW_DIRS)/pw1.c -o $(PW_DIRS)/pw1.o

clean:
	rm -f $(TARGET) *.o $(addprefix $(PW_DIRS)/, *.o)

.PHONY: all clean
