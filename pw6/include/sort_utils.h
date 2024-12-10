#ifndef SORT_UTILS_H
#define SORT_UTILS_H


void selection_sort(int *arr, int size);
void bubble_sort(int *arr, int size);
void insertion_sort(int *arr, int size);
void merge_sort(int *arr, int left, int right);
void quick_sort_descending(int *arr, int low, int high);
void left_rotate(int *arr, int size, int n);
void sort_string(char *str);
void character_frequency(char *str);
void randomize_array(int *arr, int size);
#endif
