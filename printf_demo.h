#ifndef PRINTF_DEMO_H
#define PRINTF_DEMO_H

/* Libraries */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* Global Variables */
const char* pointer_value;
char* string_value;
int* char_value;
int* int_value;
double* double_value;
int* character_count;

/* Function Prototypes */
int my_printf(const char* format, ...);
int convert_string(char* string_value, int length, int character_count);
void num_of_digits(int* num, int* digit_count);
void convert_to_positive(int* num);
void convert_integer_to_ascii(int* int_value, int* digit_count, char* integer_to_string);

#endif //PRINTF_DEMO_H