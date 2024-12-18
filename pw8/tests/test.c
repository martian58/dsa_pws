/**
 * Filename:    test.c
 * Author:      Fuad Alizada 
 * Purpose:     Test functions for Practical Work 8.
 */

#include <stdio.h>
#include <assert.h>
#include "tasks.h"

int main() {
    printf("Running tests...\n");

    // Test 1: Append and Print Linked List
    Node* head = NULL;
    append_linked_list(&head, 1);
    append_linked_list(&head, 2);
    append_linked_list(&head, 3);
    assert(head->data == 1 && head->next->data == 2 && head->next->next->data == 3);
    printf("Test 1: Append and Print Linked List passed ✅\n");

    // Test 2: FrontBackSplit
    Node *front = NULL, *back = NULL;
    front_back_split(head, &front, &back);
    assert(front->data == 1 && front->next->data == 2 && front->next->next == NULL);
    assert(back->data == 3 && back->next == NULL);
    printf("Test 2: FrontBackSplit passed ✅\n");

    // Test 3: SortedMerge
    Node* list1 = NULL;
    Node* list2 = NULL;
    append_linked_list(&list1, 1);
    append_linked_list(&list1, 3);
    append_linked_list(&list2, 2);
    append_linked_list(&list2, 4);
    Node* merged = sorted_merge(list1, list2);
    assert(merged->data == 1 && merged->next->data == 2 && merged->next->next->data == 3 && merged->next->next->next->data == 4);
    printf("Test 3: SortedMerge passed ✅\n");

    // Test 4: MergeSort
    Node* unsorted = NULL;
    append_linked_list(&unsorted, 4);
    append_linked_list(&unsorted, 1);
    append_linked_list(&unsorted, 3);
    append_linked_list(&unsorted, 2);
    Node* sorted = merge_sort(unsorted);
    assert(sorted->data == 1 && sorted->next->data == 2 && sorted->next->next->data == 3 && sorted->next->next->next->data == 4);
    printf("Test 4: MergeSort passed ✅\n");

    // Test 5: RemoveDuplicates
    Node* duplicates = NULL;
    append_linked_list(&duplicates, 1);
    append_linked_list(&duplicates, 1);
    append_linked_list(&duplicates, 2);
    append_linked_list(&duplicates, 3);
    append_linked_list(&duplicates, 3);
    remove_duplicates(duplicates);
    assert(duplicates->data == 1 && duplicates->next->data == 2 && duplicates->next->next->data == 3 && duplicates->next->next->next == NULL);
    printf("Test 5: RemoveDuplicates passed ✅\n");

    // Test 6: Reverse Linked List (Iterative)
    Node* reversed_iterative = reverse_list_iterative(sorted);
    assert(reversed_iterative->data == 4 && reversed_iterative->next->data == 3 && reversed_iterative->next->next->data == 2 && reversed_iterative->next->next->next->data == 1); // ugh...
    printf("Test 6: Reverse Linked List (Iterative) passed ✅\n");

    // Test 7: Reverse Linked List (Recursive)
    Node* reversed_recursive = reverse_list_recursive(reversed_iterative);
    assert(reversed_recursive->data == 1 && reversed_recursive->next->data == 2 && reversed_recursive->next->next->data == 3 && reversed_recursive->next->next->next->data == 4);
    printf("Test 7: Reverse Linked List (Recursive) passed ✅\n");

    // Free the memmory memory
    free_list(front);
    free_list(back);
    free_list(merged);
    free_list(sorted);
    free_list(duplicates);
    free_list(reversed_iterative);
    free_list(reversed_recursive);

    printf("All tests passed successfully! 👍👍\n\n");
    printf("Type './main' to run the main program!\n");
    return 0;
}
