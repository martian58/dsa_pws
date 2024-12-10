/**
 * Filename:    sort_utils.c
 * Author:      Fuad Alizada
 * Purpose:     This file contains utility functions for PW 6 exercises.
 * Domain:      Public 
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "sort_utils.h"


/**
 * @brief Performs `selection sort` on an integer array.
 * 
 * This function sorts an array in ascending order by repeatedly 
 * finding the smallest element from the unsorted part and swapping 
 * it with the first element of the unsorted part.
 * 
 * @param arr Pointer to the array to sort.
 * @param size Number of elements in the array.
 */
void selection_sort(int *arr, int size) {
    // Loop through each element of the array except the last one.
    for (int i = 0; i < size - 1; i++) {
        // Take the current index as the minimum.
        int min_idx = i;

        // Loop through the unsorted part of the array to find the minimum element.
        for (int j = i + 1; j < size; j++) {
            // If a smaller element is found, update the index of the minimum element.
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the smallest element found with the first element of the unsorted part.
        // Only perform the swap if the minimum index has changed.
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

/**
 * @brief Performs `bubble sort` on an integer array.
 * 
 * @param arr Pointer to the array to sort.
 * @param size Number of elements in the array.
 */
void bubble_sort(int *arr, int size) {
    // Loop through each element of the array except the last one.
    for (int i = 0; i < size - 1; i++) {
        // Loop through array a second time
        for (int j = 0; j < size - i - 1; j++) {
            // If a smaller number comes after the number, just swap them.
            if (arr[j] > arr[j + 1]) {
                // Use a `temp` variable to swap two elements of the array
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * @brief Performs insertion sort on an integer array.
 * 
 * @param arr Pointer to the array to sort.
 * @param size Number of elements in the array.
 */
void insertion_sort(int *arr, int size) {
    // Loop through the array
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/**
 * @brief Merges two subarrays of an array into a single sorted array.
 * 
 * This function is a helper for merge sort. It combines two sorted halves 
 * into a single sorted one.
 * 
 * @param arr The array containing the subarrays to merge.
 * @param left The starting index of the first subarray.
 * @param mid The ending index of the first subarray.
 * @param right The ending index of the second subarray.
 */
void merge(int *arr, int left, int mid, int right) {
    // Calculate sizes of the two subarrays
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    // Merge the temporary arrays back into `arr`
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    // Copy remaining elements of L[] and R[], if any
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

/**
 * @brief Recursively sorts an array using the merge sort algorithm.
 * 
 * This function splits the array into halves, recursively sorts them, and 
 * merges the sorted halves using the `merge` function.
 * 
 * @param arr The array to sort.
 * @param left The starting index of the array segment.
 * @param right The ending index of the array segment.
 */
void merge_sort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}


/**
 * @brief Partitions an array for QuickSort using a pivot element.
 * 
 * This function places the pivot element at its correct position in a 
 * sorted array and moves all larger elements to the left and smaller 
 * elements to the right (for descending order).
 * 
 * @param arr The array to partition.
 * @param low The starting index of the segment to partition.
 * @param high The ending index of the segment to partition.
 * @return The index of the pivot after partitioning.
 */
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) {  // Arrange in descending order
            int temp = arr[++i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}


/**
 * @brief Recursively sorts an array in descending order using QuickSort.
 * 
 * This function uses the `partition` function to divide the array into 
 * subarrays and sorts them recursively.
 * 
 * @param arr The array to sort.
 * @param low The starting index of the array segment.
 * @param high The ending index of the array segment.
 */
void quick_sort_descending(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort the subarrays
        quick_sort_descending(arr, low, pi - 1);
        quick_sort_descending(arr, pi + 1, high);
    }
}



// Exercise 3

/**
 * @brief Rotates an array to the left by n positions.
 * 
 * This function shifts the first n elements to the end of the array while 
 * keeping the order of the remaning elements.
 * 
 * @param arr The array to rotate.
 * @param size The size of the array.
 * @param n The number of positions to rotate.
 */
void left_rotate(int *arr, int size, int n) {
    n %= size; 
    int temp[n];

    // Store the first n elements in a temporary array
    for (int i = 0; i < n; i++) temp[i] = arr[i];

    // Shift remaining elements to the left
    for (int i = n; i < size; i++) arr[i - n] = arr[i];

    // Copy temporary elements to the end
    for (int i = 0; i < n; i++) arr[size - n + i] = temp[i];
}


// Exercise 4

/**
 * @brief Sorts a string alphabetically.
 * 
 * This function uses a simple bubble sort algorithm to arrange the 
 * characters of a string in ascending order.
 * 
 * @param str The string to sort.
 */
void sort_string(char *str) {
    int len = strlen(str);

    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}


/**
 * @brief Counts and displays the frequency of each character in a string.
 * 
 * This function counts how often each character appears in the string and 
 * prints the frequency of characters with occurrences.
 * 
 * @param str The string to analyze.
 */
void character_frequency(char *str) {
    int freq[256] = {0};  // Array to store frequencies of all characters

    // Count the frequency of each character
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    // Display frequencies
    printf("Character frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", i, freq[i]);
        }
    }
}

// Self added functions.

/**
 * @brief Randomizes an array's element order.
 * 
 * This function loops through an array and swaps each element with a randomly
 * selected element
 * 
 * @param arr The array to randomize.
 * @param size The size of the array.
 */
void randomize_array(int *arr, int size) {
    // Seed for random number generator
    srand(time(NULL));

    for (int i = size - 1; i > 0; i--) {
        // Generate a random index in the range of 0 and i
        int j = rand() % (i + 1);

        // Swap arr[i] with arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
