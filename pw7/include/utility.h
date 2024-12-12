#ifndef UTILITY_H
#define UTILITY_H

#include <stdbool.h>

/**
 * @brief Checks if the given character is an opening bracket.
 * 
 * @param ch The character to check.
 * @return true if the character is an opening bracket, false otherwise.
 */
bool isOpeningBracket(char ch);

/**
 * @brief Checks if the given character is a closing bracket.
 * 
 * @param ch The character to check.
 * @return true if the character is a closing bracket, false otherwise.
 */
bool isClosingBracket(char ch);

/**
 * @brief Matches a closing bracket with its corresponding opening bracket.
 * 
 * @param opening The opening bracket character.
 * @param closing The closing bracket character.
 * @return true if the brackets match, false otherwise.
 */
bool isMatchingPair(char opening, char closing);

/**
 * @brief Checks if the given expression has balanced parentheses.
 * 
 * @param expression The expression to check.
 * @return true if the parentheses are balanced, false otherwise.
 */
bool isBalanced(const char *expression);

/**
 * @brief Finds the next greater element for each element in the array.
 * 
 * @param arr The input array.
 * @param size The size of the array.
 * @param result The output array containing the next greater elements.
 */
void nextGreaterElement(int *arr, int size, int *result);

#endif // UTILITY_H
