/**
 * File:          array_u.c
 * Author:        Fuad Alizada
 * Date:          27 Nov 2024
 * Description:   This file contains core functions for PW5 exercises.
 */

#include <stdio.h>
#include "array_u.h"

/**
 * @brief This function reads elements into an array from user.
 * 
 * 
 * @param arr Pointer to the array to store elements.
 * @param size Number of elements to read.
 */
void read_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}


// Ex. 1

/**
 * @brief This function calculates the sum of all elements in an array.
 * 
 * 
 * @param arr Pointer to the array.
 * @param size Number of elements in the array.
 * @return The sum of the elements in the array.
 */
int sum_elements(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}



// Ex. 2

/**
 * @brief This function separates the elements of an array into odd and even numbers.
 * 
 * This function divides the input array into two separate arrays 
 * containing odd and even numbers, respectively.
 * 
 * @param arr Pointer to the original array.
 * @param size Number of elements in the array.
 * @param odds Pointer to the array to store odd numbers.
 * @param evens Pointer to the array to store even numbers.
 * @param odd_count Pointer to store the count of odd numbers.
 * @param even_count Pointer to store the count of even numbers.
 */
void separate_odd_even(int *arr, int size, int *odds, int *evens, int *odd_count, int *even_count) {
    *odd_count = *even_count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evens[(*even_count)++] = arr[i];
        } else {
            odds[(*odd_count)++] = arr[i];
        }
    }
}




// Ex. 3

/**
 * @brief This function searches for an element in an array.
 * 
 * This function looks for the specified element in the array. If found,
 * it returns the index of the element; otherwise, it returns -1.
 * 
 * @param size Number of elements in the array.
 * @param arr Pointer to the array.
 * @param elem_to_search The element to search for.
 * @return int The index of the element if found, -1 otherwise.
 */
int search(int size, int *arr, int elem_to_search) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == elem_to_search) {
            return i;
        }
    }
    return -1;
}


// Ex. 4

/**
 * @brief This function reverses the elements of an array in place.
 * 
 * This function swaps elements from the start and the 
 * end of the array until the array is reversed.
 * 
 * @param arr Pointer to the array.
 * @param size Number of elements in the array.
 */
void reverse_array(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}


/**
 * @brief This function reverses the characters of a string in place.
 * 
 * This function swaps characters from start and end
 * of the string until the entire string is reversed.
 * 
 * @param str Pointer to the string to reverse.
 */
void reverse_string(char *str) {

    // Find the lenght by traversing through the string until 
    // a null terminator is found to find the length of the string.
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}



// Ex. 5

/**
 * @brief This function finds the maximum value in an array.
 * 
 * This function iterates through the array to find and return 
 * the maximum element.
 * 
 * @param arr Pointer to the array.
 * @param size Number of elements in the array.
 * @return int The maximum value in the array.
 */
int find_max(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            // update the `max`
            max = arr[i];
        }
    }
    return max;
}