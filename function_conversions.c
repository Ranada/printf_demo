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


void convert_integer_to_ascii(int int_value, int digit_count, char* integer_to_string)
{
    if (int_value < 0)
    {
        int_value = -1 * (int_value);
        (digit_count)++;
    }

    integer_to_string[digit_count] = '\0';

    if (int_value == 0)
    {
        integer_to_string[digit_count - 1] = '0';
    }

    if (int_value > 0)
    {
        while (int_value > 0)
        {        
        char digit_to_char = (int_value) % 10 + '0';
        
        int_value = int_value / 10;

        integer_to_string[(digit_count) - 1] = digit_to_char;

        (digit_count)--;
        }
        write(1, integer_to_string, digit_count);
    }


    // if (*digit_count == -1)
    //     string[0] = '-';

    // return string;
}