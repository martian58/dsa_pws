#ifndef DSA_PROJECT_H
#define DSA_PROJECT_H

// Define the structure for a voter
struct elector {
    char name[100];       // Name of the voter
    long cin_num;         // Voter's ID number
    int choice;           // Vote choice (1 to 4, or 5 for others)
    struct elector* next; // Pointer to the next voter
};

typedef struct elector* T_Elector;

// Function Prototypes
T_Elector creationelector(void);
void displaylist(T_Elector head);
void addelector(T_Elector *head, char name[], long cin_num, int choice);
int countelector(T_Elector head);
int findelector(T_Elector head, long cin_num);
void deletelector(T_Elector *head, long cin_num);
void decomposelist(T_Elector head, T_Elector *left, T_Elector *right, T_Elector *white);
void sortlist(T_Elector *head);
T_Elector mergelists(T_Elector left, T_Elector right);
int countLR(T_Elector head);
void freelist(T_Elector *head);

#endif
