#include <stdio.h>
#include <stdlib.h>
#include "dsaproject.h"

int main() {
    T_Elector head = NULL, left = NULL, right = NULL, white = NULL;
    int choice;
    long id;
    char name[100];

    while (1) {
        printf("\nElection Management Menu:\n");
        printf("1. Enter Voters\n");
        printf("2. Add Voter\n");
        printf("3. Delete Voter\n");
        printf("4. Search Voter\n");
        printf("5. Display Voters\n");
        printf("6. Count Voters\n");
        printf("7. Split Voters into Lists\n");
        printf("8. Merge Left and Right Lists\n");
        printf("9. Count Left and Right Voters\n");
        printf("10. Free Lists\n");
        printf("11. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = creationelector();
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter ID number: ");
                scanf("%ld", &id);
                printf("Enter choice (1-4 or 5): ");
                scanf("%d", &choice);
                addelector(&head, name, id, choice);
                break;
            case 3:
                printf("Enter ID number to delete: ");
                scanf("%ld", &id);
                deletelector(&head, id);
                break;
            case 4:
                printf("Enter ID number to search: ");
                scanf("%ld", &id);
                findelector(head, id);
                break;
            case 5:
                displaylist(head);
                break;
            case 6:
                printf("Total Voters: %d\n", countelector(head));
                break;
            case 7:
                decomposelist(head, &left, &right, &white);
                printf("Voters split into Left, Right, and White lists.\n");
                break;
            case 8:
                head = mergelists(left, right);
                printf("Left and Right lists merged.\n");
                break;
            case 9:
                printf("Left and Right Voters count: %d\n", countLR(head));
                break;
            case 10:
                freelist(&head);
                printf("Lists freed.\n");
                break;
            case 11:
                freelist(&head);
                printf("Goodbye.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
