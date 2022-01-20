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

int num_of_digits(int num)
{
    int digit_count = 0;

    if (num == 0)
    {
        digit_count++;
    }
    
    else
    {
        while(num > 0)
        {
        digit_count++;
        num /= 10;
        }
    }

    return digit_count;
}


char* integer_to_ascii(int num)
{
    char *string;
    int digit_count = 0;

    if(num < 0)
    {
        num = -1 * num;
        digit_count++;
    }

    digit_count += num_of_digits(num);   
    string = malloc(sizeof(char)*(digit_count + 1));

    string[digit_count] = '\0';

    if (num == 0)
    {
        string[digit_count - 1] = '0';
    }

    else
    {
        while(num > 0)
        {
        string[digit_count - 1] = num % 10 + '0';
        num = num / 10;
        digit_count--;
        }
    }


    if (digit_count == -1)
        string[0] = '-';

    return string;
}