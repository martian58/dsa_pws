# Compiler
CC = gcc

# flags
CFLAGS = -Wall -g

# Directories neeeded
BUILD_DIR = build

# Source files
SRC_PW2 = pw2.c
SRC_TEST = test.c
SRC_EX1 = ex1.c
SRC_EX4 = ex4.c
SRC_EX5 = ex5.c
SRC_EX6 = ex6.c

# Object files
OBJ_PW2 = $(BUILD_DIR)/pw2.o
OBJ_TEST = $(BUILD_DIR)/test.o
OBJ_EX1 = $(BUILD_DIR)/ex1.o
OBJ_EX4 = $(BUILD_DIR)/ex4.o
OBJ_EX5 = $(BUILD_DIR)/ex5.o
OBJ_EX6 = $(BUILD_DIR)/ex6.o

# Executabls
EXEC_TEST = test
EXEC_EX1 = ex1
EXEC_EX4 = ex4
EXEC_EX5 = ex5
EXEC_EX6 = ex6

# Targets
all: $(EXEC_TEST) $(EXEC_EX1) $(EXEC_EX4) $(EXEC_EX5) $(EXEC_EX6)

$(EXEC_TEST): $(OBJ_PW2) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

$(EXEC_EX1): $(OBJ_EX1)
	$(CC) $(CFLAGS) -o $@ $^

$(EXEC_EX4): $(OBJ_PW2) $(OBJ_EX4)
	$(CC) $(CFLAGS) -o $@ $^

$(EXEC_EX5): $(OBJ_PW2) $(OBJ_EX5)
	$(CC) $(CFLAGS) -o $@ $^

$(EXEC_EX6): $(OBJ_PW2) $(OBJ_EX6)
	$(CC) $(CFLAGS) -o $@ $^




# Compile source files into object files

$(OBJ_PW2): pw2.c pw2.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c pw2.c -o $@

$(OBJ_TEST): test.c pw2.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c test.c -o $@

$(OBJ_EX1): ex1.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c ex1.c -o $@

$(OBJ_EX4): ex4.c pw2.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c ex4.c -o $@

$(OBJ_EX5): ex5.c pw2.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c ex5.c -o $@

$(OBJ_EX6): ex6.c pw2.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c ex6.c -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)



# Cleanup object and executable files
clean:
	rm -f $(BUILD_DIR)/*.o $(EXEC_TEST) $(EXEC_EX1) $(EXEC_EX4) $(EXEC_EX5) $(EXEC_EX6)

.PHONY: all clean
