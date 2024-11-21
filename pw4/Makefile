CC = gcc
CFLAGS = -Iinclude -Wall # To show all the warnings


BUILD_DIR = build


SRC = src/main.c src/factorial.c src/gcd.c
TEST_SRC = tests/test.c


OBJ = $(BUILD_DIR)/main.o $(BUILD_DIR)/factorial.o $(BUILD_DIR)/gcd.o
TEST_OBJ = $(BUILD_DIR)/test.o $(BUILD_DIR)/factorial.o $(BUILD_DIR)/gcd.o


TARGET = main
TEST_EXEC = test

.PHONY: all clean

all: $(TARGET) $(TEST_EXEC)
	./$(TEST_EXEC)  # Run the tests

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: tests/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_EXEC): $(TEST_OBJ)
	$(CC)  $(TEST_OBJ) -o $(TEST_EXEC)  

clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_EXEC)
