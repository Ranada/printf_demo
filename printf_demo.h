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
int int_value;
double double_value;
int character_count;

/* Function Prototypes */
int my_printf(const char* format, ...);
int convert_string(char* string_value, int length, int character_count);
int no_of_digits(int num);
char* integer_to_ascii(int num);

#endif //PRINTF_DEMO_H