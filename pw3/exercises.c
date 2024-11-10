/*
 * Copyright:	   Public domain.
 * 
 * Fileanme:       exercises.c
 * Authors:        Fuad Alizada
 * Website:	       https://fuad1234.pythonanywhere.com
 * Date:           Nov 10, 2024
 * Description:    File contains functions for the exercises from Practical Work 3. 
 * 
*/

#include <stdio.h>
#include <ctype.h>

/**
 * @brief Check if a number is divisible by 7.
 * 
 * @param n The integer to check.
 * @return  1 if divisible by 7, 0 otherwise.
 */
int is_divisible_by_7(int n) {
    return n % 7 == 0;
}

/**
 * @brief Determine if a given year is a leap year.
 * 
 * A leap year occurs every 4 years, but not every 100 years, unless it is every 400 years.
 * 
 * @param year the year to check.
 * @return  1 if the year is a leap year, 0 otherwise.
 */
int is_leap_year(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

/**
 * @brief Calculatr the length of a given string.
 * 
 * @param str Pointer to the string.
 * @return int The length of the string.
 */
int my_strlen(const char *str) {
    int length = 0;
    while (*str++) length++;
    return length;
}

/**
 * @brief Check if a characther is an alphabetic letter.
 * 
 * @param c the characther to check.
 * @return 1 if the characther is a letter, 0 otherwise.
 */
int my_isalpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

/**
 * @brief Check if a characther is a digit.
 * 
 * This function checks if the characther is between '0' and '9'.
 * 
 * @param c The characther to check.
 * @return int 1 if the characther is a digit, 0 otherwise.
 */
int my_isdigit(char c) {
    return c >= '0' && c <= '9';
}

/**
 * @brief Convert a lowercase characther to upercase.
 * 
 * If the characther is lowercase, it will be converted to upercase, otherwise, it remains unchanged.
 * 
 * @param c The characther to convert.
 * @return char The upercase version of the characther, or the original characther if it is not lowercase.
 */
char my_touper(char c) {
    return (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c;
}

/**
 * @brief Convert an upercase characther to lowercase.
 * 
 * If the characther is upercase, it will be converted to lowercase; otherwise, it remains unchanged.
 * 
 * @param c The characther to convert.
 * @return char The lowercase version of the characther, or the original characther if it is not upercase.
 */
char my_tolower(char c) {
    return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
}

/**
 * @brief Compare two strings for equality.
 * 
 * This function compares two strings characther by characther. If the strings are
 * identical, it returns 1; otherwise, it returns 0.
 * 
 * @param str1 The first string.
 * @param str2 The second string.
 * @return int 1 if the strings are equal, 0 otherwise.
 */
int my_strcmp(const char *str1, const char *str2) {
    while (*str1 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 == *str2;
}

/**
 * @brief Concatenate two strings.
 * 
 * Appends the source string to the destination string. Assumes that the destination
 * buffer has enough space to hold the concatenated result.
 * 
 * @param dest The destination string (must have enough space).
 * @param src The source string.
 * @return char* Pointer to the destination string with `src` appended.
 */
char* my_strcat(char *dest, const char *src) {
    char *ptr = dest;
    while (*ptr) ptr++;
    while ((*ptr++ = *src++));
    return dest;
}

/**
 * @brief Copy a source string to a destination string.
 * 
 * Copies the content of the source string into the destination buffer.
 * Assumes that the destination buffer is large enough.
 * 
 * @param dest The destination buffer.
 * @param src The source string.
 * @return char* Pointer to the destination string.
 */
char* my_strcpy(char *dest, const char *src) {
    char *ptr = dest;
    while ((*ptr++ = *src++));
    return dest;
}
