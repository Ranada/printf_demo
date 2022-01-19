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