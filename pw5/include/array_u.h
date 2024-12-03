// Compile guards
#ifndef ARRAY_U_H
#define ARRAY_U_H


// Function Prototypes 
void read_array(int *arr, int size);
int sum_elements(int *arr, int size);
void separate_odd_even(int *arr, int size, int *odds, int *evens, int *odd_count, int *even_count);
int search(int size, int *arr, int elem_to_search);
void reverse_array(int *arr, int size);
void reverse_string(char *str);
int find_max(int *arr, int size);

#endif
