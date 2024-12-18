#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dsaproject.h"

/**
 * Function to create a voter and return the pointer to the voter structure.
 * 
 * This function prompts the user to enter the voter's name, ID number (cin_num),
 * and their choice (1-4 or 5). It dynamically allocates memory for the new voter
 * and initializes the structure fields.
 *
 * @return T_Elector - pointer to the newly created voter structure.
 */
T_Elector creationelector(void) {
    T_Elector newVoter = (T_Elector)malloc(sizeof(struct elector));
    printf("Enter voter's name: ");
    scanf("%s", newVoter->name);
    printf("Enter voter's ID number: ");
    scanf("%ld", &newVoter->cin_num);
    printf("Enter voter's choice (1-4 or 5): ");
    scanf("%d", &newVoter->choice);
    newVoter->next = NULL;
    return newVoter;
}

/**
 * Function to display the list of voters.
 * 
 * This function iterates through the linked list of voters and displays each voter's
 * name, ID number, and vote choice.
 * 
 * @param head T_Elector - pointer to the head of the voters list.
 */
void displaylist(T_Elector head) {
    T_Elector current = head;
    printf("Voter List:\n");
    while (current) {
        printf("Name: %s, ID: %ld, Choice: %d\n", current->name, current->cin_num, current->choice);
        current = current->next;
    }
}

/**
 * Function to add a voter to the list alphabetically by name.
 * 
 * This function creates a new voter and inserts them into the list while maintaining
 * alphabetical order based on the voter's name.
 * 
 * @param head T_Elector* - pointer to the head of the voters list.
 * @param name char[] - name of the new voter.
 * @param cin_num long - ID number of the new voter.
 * @param choice int - choice made by the new voter.
 */
void addelector(T_Elector *head, char name[], long cin_num, int choice) {
    T_Elector newVoter = (T_Elector)malloc(sizeof(struct elector));
    strcpy(newVoter->name, name);
    newVoter->cin_num = cin_num;
    newVoter->choice = choice;
    newVoter->next = NULL;

    // If list is empty or new voter should be placed at the beginning
    if (*head == NULL || strcmp((*head)->name, newVoter->name) > 0) {
        newVoter->next = *head;
        *head = newVoter;
        return;
    }

    // Insert new voter in the correct alphabetical position
    T_Elector current = *head;
    while (current->next && strcmp(current->next->name, newVoter->name) < 0) {
        current = current->next;
    }

    newVoter->next = current->next;
    current->next = newVoter;
}

/**
 * Function to count the number of voters in the list.
 * 
 * This function iterates through the linked list and counts the number of voters.
 * 
 * @param head T_Elector - pointer to the head of the voters list.
 * @return int - number of voters in the list.
 */
int countelector(T_Elector head) {
    int count = 0;
    T_Elector current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

/**
 * Function to find a voter by their ID and display their information.
 * 
 * This function searches the list for a voter by their ID number and prints their details.
 * If the voter is not found, it returns 0.
 * 
 * @param head T_Elector - pointer to the head of the voters list.
 * @param cin_num long - ID number of the voter to search for.
 * @return int - returns 1 if the voter is found, 0 otherwise.
 */
int findelector(T_Elector head, long cin_num) {
    T_Elector current = head;
    while (current) {
        if (current->cin_num == cin_num) {
            printf("Voter found: Name: %s, ID: %ld, Choice: %d\n", current->name, current->cin_num, current->choice);
            return 1;
        }
        current = current->next;
    }
    return 0;
}

/**
 * Function to delete a voter by their ID number.
 * 
 * This function removes a voter from the list based on their ID number. It ensures the 
 * list remains properly linked after the deletion.
 * 
 * @param head T_Elector* - pointer to the head of the voters list.
 * @param cin_num long - ID number of the voter to delete.
 */
void deletelector(T_Elector *head, long cin_num) {
    T_Elector current = *head;
    T_Elector prev = NULL;

    while (current) {
        if (current->cin_num == cin_num) {
            // Remove the voter from the list
            if (prev) {
                prev->next = current->next;
            } else {
                *head = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

/**
 * Function to split the list into three sub-lists based on voter's choice.
 * 
 * This function divides the original list into three sub-lists: left, right, and white,
 * based on the voter's choice. Voters choosing NAME1 or NAME3 go into the left list,
 * NAME2 or NAME4 into the right list, and others into the white list.
 * 
 * @param head T_Elector - pointer to the head of the original voters list.
 * @param left T_Elector* - pointer to the left sub-list.
 * @param right T_Elector* - pointer to the right sub-list.
 * @param white T_Elector* - pointer to the white sub-list.
 */
void decomposelist(T_Elector head, T_Elector *left, T_Elector *right, T_Elector *white) {
    T_Elector current = head;
    while (current) {
        if (current->choice == 1 || current->choice == 3) {
            addelector(left, current->name, current->cin_num, current->choice);
        } else if (current->choice == 2 || current->choice == 4) {
            addelector(right, current->name, current->cin_num, current->choice);
        } else {
            addelector(white, current->name, current->cin_num, current->choice);
        }
        current = current->next;
    }
}

/**
 * Function to sort the list by voter ID number.
 * 
 * This function sorts the list in ascending order based on the voter's ID number using
 * a simple bubble sort technique.
 * 
 * @param head T_Elector* - pointer to the head of the voters list.
 */
void sortlist(T_Elector *head) {
    if (*head == NULL || (*head)->next == NULL) return;

    T_Elector current = *head;
    T_Elector index = NULL;
    long tempCin;
    char tempName[100];
    int tempChoice;

    while (current) {
        index = current->next;
        while (index) {
            if (current->cin_num > index->cin_num) {
                // Swap the data
                tempCin = current->cin_num;
                strcpy(tempName, current->name);
                tempChoice = current->choice;

                current->cin_num = index->cin_num;
                strcpy(current->name, index->name);
                current->choice = index->choice;

                index->cin_num = tempCin;
                strcpy(index->name, tempName);
                index->choice = tempChoice;
            }
            index = index->next;
        }
        current = current->next;
    }
}

/**
 * Function to merge two lists (left and right) while keeping the order by ID.
 * 
 * This function merges two sorted lists (left and right) into a new list while maintaining
 * the order based on the voter ID number.
 * 
 * @param left T_Elector - pointer to the head of the left list.
 * @param right T_Elector - pointer to the head of the right list.
 * @return T_Elector - pointer to the merged list.
 */
T_Elector mergelists(T_Elector left, T_Elector right) {
    T_Elector merged = NULL;

    while (left && right) {
        if (left->cin_num < right->cin_num) {
            addelector(&merged, left->name, left->cin_num, left->choice);
            left = left->next;
        } else {
            addelector(&merged, right->name, right->cin_num, right->choice);
            right = right->next;
        }
    }

    while (left) {
        addelector(&merged, left->name, left->cin_num, left->choice);
        left = left->next;
    }

    while (right) {
        addelector(&merged, right->name, right->cin_num, right->choice);
        right = right->next;
    }

    return merged;
}

/**
 * Function to count the number of left voters in the merged list.
 * 
 * This function counts the number of voters in the merged list who chose either NAME1
 * or NAME3 (left-wing candidates).
 * 
 * @param head T_Elector - pointer to the head of the merged list.
 * @return int - number of left voters in the merged list.
 */
int countLR(T_Elector head) {
    int count = 0;
    T_Elector current = head;
    while (current) {
        if (current->choice == 1 || current->choice == 3) {
            count++;
        }
        current = current->next;
    }
    return count;
}

/**
 * Function to free the entire list.
 * 
 * This function deallocates the memory used by the list, freeing each voter structure.
 * 
 * @param head T_Elector* - pointer to the head of the voters list.
 */
void freelist(T_Elector *head) {
    T_Elector current = *head;
    T_Elector next = NULL;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}
