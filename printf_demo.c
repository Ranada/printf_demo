#include "printf_demo.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int my_printf(const char* format, ...)
{
    va_list args_pointer; // Points to each agrument in the list
    const char* pointer_value;
    char* string_value;
    int int_value;
    double double_value;
    int done = 0;

    va_start(args_pointer, format); // Looks at the first REQUIRED argument then finds and point to the first OPTIONAL argument

    for (pointer_value = format; *pointer_value; pointer_value++)
    {
        if (*pointer_value != '%')
        {
            putchar(*pointer_value);
            continue;
        }
        switch (*++pointer_value)
        {
            case 'd':
                int_value = va_arg(args_pointer, int);
                printf("%d", int_value);
                break;
            case 'f':
                double_value = va_arg(args_pointer, double);
                printf("%f", double_value);
                break;
            case 's':
                for (string_value = va_arg(args_pointer, char*);  *string_value; string_value++)
                    putchar(*string_value);
                break;
            default:
                putchar(*pointer_value);
                break;
        }
    }
    va_end(args_pointer); //Clean up argument list

    return done;
}

// int main()
// {
//     my_printf("hello world.\n");
    
//     return 0;
// }