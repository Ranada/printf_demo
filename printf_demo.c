#include "printf_demo.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int my_printf(const char* format, ...)
{
    va_list args_pointer; // Points to each agrument in the list
    const char* pointer_value;
    char* string_value;
    int int_value;
    double double_value;
    int character_count = 0;
    //int done = 0;

    va_start(args_pointer, format); // Looks at the first REQUIRED argument then finds and point to the first OPTIONAL argument

    for (pointer_value = format; *pointer_value; pointer_value++)
    {
        if(*pointer_value != '\0')
        {
            if (*pointer_value != '%')
            {
                putchar(*pointer_value);
                character_count++;
                continue;
            }
            switch (*++pointer_value)
            {
                case 'c':
                    int_value = va_arg(args_pointer, int);
                    putchar(int_value);
                    character_count++;
                    break;
                case 'd':
                    int_value = va_arg(args_pointer, int);
                    printf("%d", int_value);
                    character_count++;
                    break;
                case 'f':
                    double_value = va_arg(args_pointer, double);
                    printf("%f", double_value);
                    character_count++;
                    break;
                case 's':
                    string_value = va_arg(args_pointer, char*);

                    if (string_value == NULL)
                    {
                        string_value = "(null)";
                        int index;
                        int length = strlen(string_value);

                        for (index = 0; index < length; index++)
                        {
                            putchar(string_value[index]);
                            character_count++;
                        }
                    }
                    else
                    {
                        int i;
                        char* string_result;
                        string_result = malloc(sizeof(char) * 100);
                        strcpy(string_result, string_value);
                        int length = strlen(string_result);

                        for (i = 0;  i < length; i++)
                        {
                        putchar(string_result[i]);
                        character_count++;
                        }
                    }
                    break;
                default:
                    putchar(*pointer_value);
                    character_count++;
                    break;
                    
                return character_count;
            }
        }
    }
    va_end(args_pointer); //Clean up argument list

    return character_count;
    //return done;
}

// int main()
// {
//     my_printf("hello world.\n");
    
//     return 0;
// }