# PW 2 

## Description
This project includes exercises from Practical Work 2. The main functionalities are implemented in a shared source file, `pw2.c`, and are tested in separate test files.

## Structure
- `pw2.c`: Contains implementations of functions used in various exercises.
- `pw2.h`: Header file for declarations of functions and constants.
- `test.c`: Main testing file that checks the functionality of all implemented functions.
- `ex1.c`: Exercise 1 implementation of algorithm step from the flowchart.
- `ex4.c`: Exercise 4 implementation that checks character types.
- `ex5.c`: Exercise 5 implementation that uses switch statements for character input.
- `ex6.c`: Exercise 6 implementation that finds the smallest and largest of three numbers and calculates their sum.
- `Makefile`: Used for compiling and managing object files.

## Functions Overview
1. `convert_seconds(int total_seconds)`: Converts total seconds into minutes and seconds.
2. `fahrenheit_to_celsius(float fahrenheit)`: Converts Fahrenheit temperature to Celsius.
3. `const char* check_character_type(char ch)`: Checks if a character is a number, lowercase letter, uppercase letter, or neither.
4. `const char* switch_character(char ch)`: Uses switch statements to return a string based on the character input.
5. `int* analyze_three_numbers(int num1, int num2, int num3)`: Analyzes three integers to find the smallest, largest, and their sum.

## Compilation Instructions
To compile the files, use the provided `Makefile`. Open a terminal, navigate to the project directory, and run:

```bash
make
```
This will create the necessary object files in the `build/` directory and generate the executable files in the current directory.

And run the following command for deleting the object and executable files:

```bash
make clean
```



## Running the Exercises
After compiling, you can run each exercise as follows:

- For the test program:
    ```bash
    ./test
    ```
- For Exercise 1:
    ```bash
    ./ex1
    ```
- For Exercise 4:
    ```bash
    ./ex4
    ```
- For Exercise 5:
    ```bash
    ./ex5
    ```
- For Exercise 6:
    ```bash
    ./ex6
    ```

## Testing
The project includes tests for each function implemented in `pw2.c`. These tests are run in the `test.c` file.


