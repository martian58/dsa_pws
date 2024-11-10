#include "pw2.h"
#include <stdio.h>
#include <string.h>

void run_test(const char* test_name, int condition) {
    if (!condition) {
        printf("Test '%s' failed.\n", test_name);
    } else {
        printf("Test '%s' passed successfully.\n", test_name);
    }
}

int main() {
    // Test convert_seconds function
    int* result_seconds = convert_seconds(366);
    run_test("convert_seconds", result_seconds[0] == 6 && result_seconds[1] == 6);

    // Test fahrenheit_to_celsius function
    float celsius = fahrenheit_to_celsius(98.6);
    run_test("fahrenheit_to_celsius", celsius >= 36.99 && celsius <= 37.01); 

    // Test check_character_type function
    run_test("check_character_type('a')", strcmp(check_character_type('a'), "lowercase") == 0);
    run_test("check_character_type('Z')", strcmp(check_character_type('Z'), "uppercase") == 0);
    run_test("check_character_type('5')", strcmp(check_character_type('5'), "number") == 0);
    run_test("check_character_type('$')", strcmp(check_character_type('$'), "not a number or letter") == 0);

    // Test switch_character function
    run_test("switch_character('1')", strcmp(switch_character('1'), "one") == 0);
    run_test("switch_character('2')", strcmp(switch_character('2'), "two") == 0);
    run_test("switch_character('3')", strcmp(switch_character('3'), "three") == 0);
    run_test("switch_character('9')", strcmp(switch_character('9'), "other character") == 0);

    // Test analyze_three_numbers function
    int* result_numbers = analyze_three_numbers(5, 8, 3);
    run_test("analyze_three_numbers(5, 8, 3)", result_numbers[0] == 3 && result_numbers[1] == 8 && result_numbers[2] == 16);
    
    result_numbers = analyze_three_numbers(12, 4, 9);
    run_test("analyze_three_numbers(12, 4, 9)", result_numbers[0] == 4 && result_numbers[1] == 12 && result_numbers[2] == 25);

    printf("All tests completed.\n");
    return 0;
}
