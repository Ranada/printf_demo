#include "printf_demo.h"

int convert_string(char* string_value, int length, int character_count)
{
    int index;
    for (index = 0; index < length; index++)
    {
        putchar(string_value[index]);
        character_count++;
    }
    return character_count;
}

int convert_to_positive(int negative_number)
{
    int converted_to_postive;
    converted_to_postive = -1 * negative_number;

    return converted_to_postive;
}

void count_digits(int number, int* digit_count)
{
    if (number == 0)
    {
        (*digit_count)++;
    }

    if (number < 0)
    {
        (*digit_count)++;
        number = convert_to_positive(number);
    }
    
    if (number > 0)
    {
        while(number > 0)
        {
        (*digit_count)++;
        number = number / 10;
        }
    }
}

void convert_to_hexadecimal(int number, int digit_count, int base, char* integer_to_string)
{
    char digit_to_char;
    
    while (number > 0)
    {
    int remainder = number % base;

    if (remainder < 10)
    {
        digit_to_char = remainder + 48;
    }
    else
    {
        digit_to_char = remainder + 55;
    }

    number = number / base;

    integer_to_string[digit_count - 1] = digit_to_char;

    digit_count--;
    }
}


void convert_integer_to_ascii(int number, int digit_count, char* integer_to_string, int base)
{    
    integer_to_string[digit_count] = '\0'; // Start building string by setting null terminator
    
    if (number < 0) // Convert negative value to positive
    {
        number = convert_to_positive(number);
        integer_to_string[0] = '-';
    }

    if (number == 0) // Create string if number is 0
    {
        integer_to_string[digit_count - 1] = '0';
    }

    if (number > 0 && base == HEXADECIMAL)
    {
        convert_to_hexadecimal(number, digit_count, base, integer_to_string);
    }

    if (number > 0 && base != HEXADECIMAL)
    {
        while (number > 0)
        {        
        char digit_to_char = (number) % base + '0';
        
        number = number / base;

        integer_to_string[digit_count - 1] = digit_to_char;

        digit_count--;
        }
    }


    // if (*digit_count == -1)
    //     string[0] = '-';

    // return string;
}