CC = gcc
CFLAGS = -Wall -g
SRC = main.c dsaproject.c
EXEC = election

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

clean:
	rm -f $(EXEC)

run: $(EXEC)
	./$(EXEC)
