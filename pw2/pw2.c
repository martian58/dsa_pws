/*
 * Copyright:	   Public domain.
 * 
 * Fileanme:       pw2.c
 * Authors:        Fuad Alizada
 * Website:	       https://fuad1234.pythonanywhere.com
 * Date:           Nov 05, 2024
 * Description:    File contains functions for the exercises from Practical Work 2. 
 * 
 * Purpose:	       This code demonstrates a collection of utility functions in C,
 *                 each designed to perform a simple, specific task: converting seconds to minutes and seconds,
 *                 converting Fahrenheit to Celsius, identifying the type of a character (e.g., number, lowercase, uppercase), 
 *                 returning a string based on character input, and analyzing three numbers to find the smallest, largest, 
 *                 and their sum. These functions each return values rather than printing directly, allowing for easy testing 
 *                 and validation.
 */


#include <stdio.h>
#include <assert.h>
#include "pw2.h"

/**
 * @brief Converts seconds to minutes and remaining seconds.
 * 
 * @param seconds The total number of seconds to be converted.
 * 
 * @return The minutes and remaining seconds as an array [minutes, seconds].
 */
int* convert_seconds(int seconds) {
    static int result[2];  // Using static to persist data outside of function scope
    result[0] = seconds / 60;
    result[1] = seconds % 60;
    return result;
}

/**
 * @brief Converts a temperature from Fahrenheit to Celsius.
 * 
 * @param fahrenheit The temperature in Fahrenheit.
 * 
 * @return The temperature in Celsius.
 */
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

/**
 * @brief Checks if a character is a number, lowercase letter, or uppercase letter.
 * 
 * @param ch The character to check.
 * 
 * @return A string description of the character type.
 */
const char* check_character_type(char ch) {
    if (ch >= '0' && ch <= '9') {
        return "number";
    } else if (ch >= 'a' && ch <= 'z') {
        return "lowercase";
    } else if (ch >= 'A' && ch <= 'Z') {
        return "uppercase";
    } else {
        return "not a number or letter";
    }
}

/**
 * @brief Displays a message based on the character input ('1', '2', '3', or other).
 * 
 * @param ch The character to check.
 * 
 * @return A string description based on the character.
 */
const char* switch_character(char ch) {
    switch (ch) {
        case '1':
            return "one";
        case '2':
            return "two";
        case '3':
            return "three";
        default:
            return "other character";
    }
}

/**
 * @brief Finds and returns the smallest, largest, and sum of three numbers.
 * 
 * @param num1 First integer.
 * @param num2 Second integer.
 * @param num3 Third integer.
 * 
 * @return An array of three integers [smallest, largest, sum].
 */
int* analyze_three_numbers(int num1, int num2, int num3) {
    static int result[3];
    result[0] = (num1 < num2 && num1 < num3) ? num1 : (num2 < num3 ? num2 : num3);
    result[1] = (num1 > num2 && num1 > num3) ? num1 : (num2 > num3 ? num2 : num3);
    result[2] = num1 + num2 + num3;
    return result;
}
