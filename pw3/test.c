#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "exercises.h"

void test_is_divisible_by_7() {
    assert(is_divisible_by_7(7) == 1 && "Test for is_divisible_by_7 with input 7 failed");
    assert(is_divisible_by_7(10) == 0 && "Test for is_divisible_by_7 with input 10 failed");
    printf("Test for test_is_divisible_by_7 passed.\n");
}

void test_is_leap_year() {
    assert(is_leap_year(2000) == 1 && "Test for is_leap_year with input 2000 failed");
    assert(is_leap_year(1900) == 0 && "Test for is_leap_year with input 1900 failed");
    assert(is_leap_year(2024) == 1 && "Test for is_leap_year with input 2024 failed");
    printf("Test for test_is_leap_year passed.\n");
}

void test_my_strlen() {
    assert(my_strlen("hello") == 5 && "Test for my_strlen(\"hello\") failed");
    assert(my_strlen("") == 0 && "Test for my_strlen(\"\") failed");
    printf("Test for test_my_strlen passed.\n");
}

void test_my_isalpha() {
    assert(my_isalpha('A') == 1 && "Test for my_isalpha('A') failed");
    assert(my_isalpha('z') == 1 && "Test for my_isalpha('z') failed");
    assert(my_isalpha('1') == 0 && "Test for my_isalpha('1') failed");
    printf("Test for test_my_isalpha passed.\n");
}

void test_my_isdigit() {
    assert(my_isdigit('0') == 1 && "Test for my_isdigit('0') failed");
    assert(my_isdigit('9') == 1 && "Test for my_isdigit('9') failed");
    assert(my_isdigit('A') == 0 && "Test for my_isdigit('A') failed");
    printf("Test for test_my_isdigit passed.\n");
}

void test_my_touper_tolower() {
    assert(my_touper('a') == 'A' && "Test for my_touper('a') failed");
    assert(my_touper('A') == 'A' && "Test for my_touper('A') failed");
    assert(my_tolower('A') == 'a' && "Test for my_tolower('A') failed");
    assert(my_tolower('a') == 'a' && "Test for my_tolower('a') failed");
    printf("Test for test_my_touper_tolower passed.\n");
}

void test_my_strcmp() {
    assert(my_strcmp("hello", "hello") == 1 && "Test for my_strcmp(\"hello\", \"hello\") failed");
    assert(my_strcmp("hello", "world") == 0 && "Test for my_strcmp(\"hello\", \"world\") failed");
    printf("Test for test_my_strcmp passed.\n");
}

void test_my_strcat() {
    char str1[50] = "Hello ";
    assert(strcmp(my_strcat(str1, "World"), "Hello World") == 0 && "Test for my_strcat(\"Hello \", \"World\") failed");
    printf("Test for test_my_strcat passed.\n");
}

void test_my_strcpy() {
    char dest[50];
    assert(strcmp(my_strcpy(dest, "Copy this!"), "Copy this!") == 0 && "Test for my_strcpy(dest, \"Copy this!\") failed");
    printf("Test for test_my_strcpy passed.\n");
}

int main() {
    test_is_divisible_by_7();
    test_is_leap_year();
    test_my_strlen();
    test_my_isalpha();
    test_my_isdigit();
    test_my_touper_tolower();
    test_my_strcmp();
    test_my_strcat();
    test_my_strcpy();
    printf("All tests passed successfully.\n");
    return 0;
}
