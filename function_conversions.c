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

void convert_to_positive(int* num)
{
    *num = -1 * (*num);
}

void num_of_digits(int* num, int* digit_count)
{
    if (*num == 0)
    {
        (*digit_count)++;
    }

    if (*num < 0)
    {
        (*digit_count)++;
        convert_to_positive(num);
    }
    
    if (*num > 0)
    {
        while(*num > 0)
        {
        (*digit_count)++;
        *num = *num / 10;
        }
    }
}


void convert_integer_to_ascii(int* int_value, int* digit_count, char* integer_to_string)
{
    if (*int_value < 0)
    {
        *int_value = -1 * (*int_value);
        (*digit_count)++;
    }

    num_of_digits(int_value, digit_count);   
    //string = malloc(sizeof(char)*(digit_count + 1));

    integer_to_string[*digit_count] = '\0';

    if (*int_value == 0)
    {
        integer_to_string[*digit_count - 1] = '0';
    }

    else
    {
        while (*int_value > 0)
        {
        integer_to_string[*digit_count - 1] = *int_value % 10 + '0';
        *int_value = *int_value / 10;
        (*digit_count)--;
        }
    }


    // if (*digit_count == -1)
    //     string[0] = '-';

    // return string;
}