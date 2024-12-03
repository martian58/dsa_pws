#include <stdio.h>
#include "../include/array_u.h"
#include <assert.h>


/* Test fro core functions */
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int arr2[] = {9, 7, 12, 20, 75};
    printf("Running tests...\n");

    assert(sum_elements(arr, 5) == 15);
    printf("Test 1: Sum Test 1 passed ✅\n");
    assert(sum_elements(arr2, 5) == 123);
    printf("Test 2: Sum Test 2 passed ✅\n");
    
    reverse_array(arr, 5);
    assert(arr[0] == 5 && arr[4] == 1);
    printf("Test 3: Reverse Test 1 passed ✅\n");

    reverse_array(arr, 5);
    assert(arr[4] == 5 && arr[4] == 5);
    printf("Test 4: Reverse Test 2 passed ✅\n");
    
    assert(search(5, arr, 3) == 2);
    printf("Test 5: Search Test 1 passed ✅\n");
    assert(search(5, arr2, 20) == 3);
    printf("Test 6: Search Test 2 passed ✅\n");
    
    assert(find_max(arr, 5) == 5);
    printf("Test 7: Find Max 1 passed ✅\n");
    assert(find_max(arr2, 75));
    printf("Test 8: Find Max 2 passed ✅\n");

    printf("All tests passed successfully!👍👍\n\n");
    printf("Type './main' to run the main program!\n");
    return 0;
}
