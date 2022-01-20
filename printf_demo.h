#ifndef PRINTF_DEMO_H
#define PRINTF_DEMO_H

/* Libraries */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* MACROS */
#define HEXADECIMAL 16
#define DECIMAL 10
#define OCTAL   8

/* Global Variables */
const char* pointer_value;
char* string_value;
int* digit_count;
int* char_value;
int* signed_decimal_value;
int* pointer_argument_value;
int* unsigned_hexadecimal_value;
int* unsigned_decimal_value;
int* unsigned_octal_value;
double* double_value;
int* character_count;
char* integer_to_string;
int base;

/* Function Prototypes */
int my_printf(const char* format, ...);
int convert_string(char* string_value, int length, int character_count);
void count_digits(int num, int* digit_count);
int convert_to_positive(int negative_number);
void convert_integer_to_ascii(int number, int digit_count, char* integer_to_string, int base);
void convert_to_hexadecimal(int number, int digit_count, int base, char* integer_to_string);

#endif //PRINTF_DEMO_H