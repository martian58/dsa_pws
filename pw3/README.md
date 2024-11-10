
# Practical Work 3 Exercises

This Project contains solutions to  C programming exercises from practical work 3.

## Exercises

1. **Divisible by 7**  
   Check if a given integer is divisible by 7.
   
2. **Leap Year**  
   Test whether a year is a leap year, considering the rule for leap years every 400 years.

3. **Custom `strlen`**  
   Write a custom `my_strlen` function that returns the length of a string without using the built-in `strlen`.

4. **Characther Checking**  
   Implement custom functions `my_isalpha` and `my_isdigit` to check if a characther is a letter or a digit, respectively.

5. **Characther Case Conversion**  
   Implement functions `my_touper` and `my_tolower` to convert characthers between upercase and lowercase.

6. **String Functions**  
   Implement the following string functions:
   - `my_strcmp`: Compare two strings for equality.
   - `my_strcat`: Concatenate two strings.
   - `my_strcpy`: Copy one string into another.


## Compilation

The project uses a `Makefile` for compilation. Simply run:
```bash
make
```
This will:
- Compile the object files (`.o`) and the main program (`main`).
- Compile the test program (`test`) and execute it to run all tests.

### Tests
Once compiled, the test program will automatically run:
```bash
./test
```
This will test all the implemented functions and print whether they pass or fail.

## Cleaning the Build Directory

To remove the compiled files and clean up the project, run:
```bash
make clean
```
This will remove the following:
- The compiled executable files (`main` and `test`).
- The object files (`.o`).
- The `build` directory containing the object files.

## File Structure

```text
├── exercises.c            # C source file with implementations of functions for exercises.
├── exercises.h            # Header file with function prototypes for includes.
├── main.c                 # Main program to test the functions
├── test.c                 # Test program with assertions for each exercise
├── Makefile               # Makefile to automate compilation and cleaning
├── README.md              # This file
```

## License

Public Domain