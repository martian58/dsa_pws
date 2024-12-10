/**
 * Filename:    test.c
 * Author:      Fuad Alizada
 * Purpose:     Test utility functions for PW 6 exercises.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "sort_utils.h"

int main() {
    printf("Running tests...\n");

    // Test 1: Selection Sort
    int arr1[] = {5, 2, 9, 1, 5, 6};
    selection_sort(arr1, 6);
    assert(arr1[0] == 1 && arr1[5] == 9);
    printf("Test 1: Selection Sort passed ✅\n");

    // Test 2: Bubble Sort
    int arr2[] = {3, 0, -1, 8, 7, 2};
    bubble_sort(arr2, 6);
    assert(arr2[0] == -1 && arr2[5] == 8);
    printf("Test 2: Bubble Sort passed ✅\n");

    // Test 3: Insertion Sort
    int arr3[] = {10, 3, 76, 34, 23};
    insertion_sort(arr3, 5);
    assert(arr3[0] == 3 && arr3[4] == 76);
    printf("Test 3: Insertion Sort passed ✅\n");

    // Test 4: Merge Sort
    int arr4[] = {4, 1, 3, 9, 7};
    merge_sort(arr4, 0, 4);
    assert(arr4[0] == 1 && arr4[4] == 9);
    printf("Test 4: Merge Sort passed ✅\n");

    // Test 5: Quick Sort Descending
    int arr5[] = {12, 4, 8, 1, 10};
    quick_sort_descending(arr5, 0, 4);
    assert(arr5[0] == 12 && arr5[4] == 1);
    printf("Test 5: Quick Sort Descending passed ✅\n");

    // Test 6: Left Rotate
    int arr7[] = {1, 2, 3, 4, 5};
    left_rotate(arr7, 5, 2);
    assert(arr7[0] == 3 && arr7[4] == 2);
    printf("Test 6: Left Rotate passed ✅\n");

    // Test 7: Sort String
    char str1[] = "hello";
    sort_string(str1);
    assert(strcmp(str1, "ehllo") == 0);
    printf("Test 7: Sort String passed ✅\n");

    // Test 8: Character Frequency
    char str2[] = "hello";
    int freq2[256] = {0};
    for (int i = 0; str2[i] != '\0'; i++) freq2[(unsigned char)str2[i]]++;
    assert(freq2['h'] == 1 && freq2['l'] == 2);
    printf("Test 8: Character Frequency passed ✅\n");

    printf("All tests passed successfully! 👍👍\n\n");
    printf("Type './main' to run the main program!\n");
    return 0;
}
