CC = gcc
CFLAGS = -Iinclude -Wall 

BUILD_DIR = build

SRC = src/main.c src/stack.c src/queue.c src/utility.c
TEST_SRC = tests/test.c


OBJ = $(BUILD_DIR)/main.o $(BUILD_DIR)/stack.o $(BUILD_DIR)/queue.o $(BUILD_DIR)/utility.o
TEST_OBJ = $(BUILD_DIR)/test.o $(BUILD_DIR)/stack.o $(BUILD_DIR)/queue.o $(BUILD_DIR)/utility.o


TARGET = main
TEST_EXEC = test

.PHONY: all clean

all: $(TARGET) $(TEST_EXEC)
	./$(TEST_EXEC) # Run the tests after compilation.

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) # Build the target executable.

$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: tests/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_EXEC): $(TEST_OBJ)
	$(CC)  $(TEST_OBJ) -o $(TEST_EXEC)  # Build the test executable.

clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_EXEC) # Clean the build directory and the executables.