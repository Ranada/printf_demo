#include "printf_demo.h"

int my_printf(const char* format, ...)
{
    va_list args_pointer; // Points to each agrument in the list
    va_start(args_pointer, format); // Looks at the first REQUIRED argument then finds and point to the first OPTIONAL argument
    
    character_count = 0;

    for (pointer_value = format; *pointer_value; pointer_value++)
    {
        if(*pointer_value != '\0')
        {
            if (*pointer_value != '%')
            {
                //putchar(*pointer_value);
                write(1, pointer_value, 1);
                character_count++;
                continue;
            }
            switch (*++pointer_value)
            {
                case 'c':
                    char_value = va_arg(args_pointer, int);
                    //putchar(int_value);
                    write(1, &char_value, 1);
                    character_count++;
                    break;
                case 'd':
                    int_value = va_arg(args_pointer, int);
                    
                    int digit_count = num_of_digits(int_value);

                    char* integer_to_string = integer_to_ascii(int_value);
                    write(1, integer_to_string, digit_count);

                    
                    character_count = character_count + digit_count;
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
                        char* null_string_value = "(null)";
                        int length = strlen(null_string_value);
                        
                        write(1, null_string_value, (length + 1));

                        character_count = character_count + length;
                    }
                    else
                    {
                        int length = strlen(string_value);
                        
                        write(1, string_value, (length + 1));
                        
                        character_count = character_count + length;
                    }
                    break;
                default:
                    //putchar(*pointer_value);
                    write(1, pointer_value, 1);
                    character_count++;
                    break;
                    
                return character_count;
            }
        }
    }
    va_end(args_pointer); //Clean up argument list

    return character_count;
}

// int main()
// {
//     my_printf("hello world.\n");
    
//     return 0;
// }