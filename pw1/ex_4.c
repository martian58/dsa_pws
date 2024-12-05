#include <stdio.h>

/*
1. Start
2. Input n grades between 0 and 10
3. Calculate the average of the grades
4. If 0 <= average < 5, display "Low average"
5. If 5 <= average <= 8, display "Good average"
6. If average > 8, display "Excellent average"
7. End
*/

int main() {
    int n, i;
    float grade, sum = 0, average;
    
    printf("Enter the number of grades: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter grade %d: ", i+1);
        scanf("%f", &grade);
        sum += grade;
    }
    
    average = sum / n;
    
    if (average < 5) {
        printf("Low average\n");
    } else if (average <= 8) {
        printf("Good average\n");
    } else {
        printf("Excellent average\n");
    }
    
    return 0;
}


