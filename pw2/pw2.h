/*
 * Copyright:	   Public domain.
 * 
 * Filename:       pw2.h
 * Authors:        Fuad Alizada
 * Website:	       https://fuad1234.pythonanywhere.com
 * Date:           Nov 05, 2024
 * Description:    Header file for pw2.c, providing declarations of utility functions
 *                 for PW 2 exercises.
 */

#ifndef PW2_H
#define PW2_H

#include <stdio.h>


// ANSI escape codes for colors
#define COLOR_RESET "\033[0m"
#define COLOR_INPUT "\033[1;36m"    // Cyan for input
#define COLOR_PROMPT "\033[1;34m"   // Blue for prompts
#define COLOR_RESULT "\033[1;32m"   // Green for results
#define COLOR_ERROR "\033[1;31m"    // Red for errors

/**
 * @brief Converts seconds to minutes and remaining seconds.
 * 
 * @param seconds The total number of seconds to be converted.
 * 
 * @return A pointer to an array [minutes, seconds].
 */
int* convert_seconds(int seconds);

/**
 * @brief Converts a temperature from Fahrenheit to Celsius.
 * 
 * @param fahrenheit The temperature in Fahrenheit.
 * 
 * @return The temperature in Celsius.
 */
float fahrenheit_to_celsius(float fahrenheit);

/**
 * @brief Checks if a character is a number, lowercase letter, or uppercase letter.
 * 
 * @param ch The character to check.
 * 
 * @return A string description of the character type.
 */
const char* check_character_type(char ch);

/**
 * @brief Displays a message based on the character input ('1', '2', '3', or other).
 * 
 * @param ch The character to check.
 * 
 * @return A string description based on the character.
 */
const char* switch_character(char ch);

/**
 * @brief Finds and returns the smallest, largest, and sum of three numbers.
 * 
 * @param num1 First integer.
 * @param num2 Second integer.
 * @param num3 Third integer.
 * 
 * @return A pointer to an array [smallest, largest, sum].
 */
int* analyze_three_numbers(int num1, int num2, int num3);

#endif /* PW2_H */
