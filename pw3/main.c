#include <stdio.h>
#include "exercises.h"

int main() {
    int n;
    printf("Enter an integer to check if divisible by 7: ");
    scanf("%d", &n);
    printf("Is divisible by 7? %s\n", is_divisible_by_7(n) ? "Yes" : "No");

    int year;
    printf("Enter a year to check if it is a leap year: ");
    scanf("%d", &year);
    printf("Is leap year? %s\n", is_leap_year(year) ? "Yes" : "No");

    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Length of string: %d\n", my_strlen(str));

    char c;
    printf("Enter a characther: ");
    scanf(" %c", &c);
    if (my_isalpha(c)) printf("Characther is a letter.\n");
    else if (my_isdigit(c)) printf("Characther is a digit.\n");
    else printf("Characther is neither a letter nor a digit.\n");

    printf("Uppercase of '%c': %c\n", c, my_touper(c));
    printf("Lowercase of '%c': %c\n", c, my_tolower(c));

    char str1[50], str2[50];
    printf("Enter first string for comparison: ");
    scanf("%s", str1);
    printf("Enter second string for comparison: ");
    scanf("%s", str2);
    printf("Strings are equal? %s\n", my_strcmp(str1, str2) ? "Yes" : "No");

    char concat[100];
    my_strcpy(concat, str1);
    my_strcat(concat, str2);
    printf("Concatenation of two strings: %s\n", concat);

    return 0;
}
