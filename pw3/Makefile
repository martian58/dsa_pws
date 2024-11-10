CC = gcc
CFLAGS = -Wall -Werror
TARGET = main
TEST = test
BUILD_DIR = build
OBJS = $(BUILD_DIR)/exercises.o

all: $(TARGET) $(TEST)

main: $(BUILD_DIR)/main.o $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(BUILD_DIR)/main.o $(OBJS)

test: $(BUILD_DIR)/test.o $(OBJS)
	$(CC) $(CFLAGS) -o $(TEST) $(BUILD_DIR)/test.o $(OBJS)
	./$(TEST)

$(BUILD_DIR)/exercises.o: exercises.c exercises.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c exercises.c -o $(BUILD_DIR)/exercises.o

$(BUILD_DIR)/main.o: main.c exercises.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c main.c -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/test.o: test.c exercises.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c test.c -o $(BUILD_DIR)/test.o

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(TARGET) $(TEST) $(BUILD_DIR)

