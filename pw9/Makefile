CC = gcc
CFLAGS = -Wall -Wextra

all: main ex4

main: src/main.c src/tasks.c
	$(CC) $(CFLAGS) -o main src/main.c src/tasks.c

ex4: src/ex4.c
	$(CC) $(CFLAGS) -o ex4 src/ex4.c

clean:
	rm -f main ex4
