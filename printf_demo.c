#include "printf_demo.h"

int my_printf(const char* format, ...)
{
    va_list args_pointer; // Points to each agrument in the list
    va_start(args_pointer, format); // Looks at the first REQUIRED argument then finds and point to the first OPTIONAL argument
    
    character_count = malloc(sizeof(int));
    char_value = malloc(sizeof(int));
    int_value = malloc(sizeof(int));
    octal_value = malloc(sizeof(int));
    //*character_count = 0;

    for (pointer_value = format; *pointer_value; pointer_value++)
    {
        if(*pointer_value != '\0')
        {
            if (*pointer_value != '%')
            {
                write(1, pointer_value, 1);
                
                (*character_count)++;
                
                continue;
            }
            switch (*++pointer_value)
            {
                case 'c':
                    *char_value = va_arg(args_pointer, int);
                    
                    write(1, char_value, 1);
                    
                    (*character_count)++;
                    
                    break;
                case 'd':
                    *int_value = va_arg(args_pointer, int);
                    
                    // int* digit_count; 
                    // char* integer_to_string;
                    
                    digit_count = malloc(sizeof(int));
                    integer_to_string = malloc(sizeof(char) * (*digit_count) + 1);
                    base = DECIMAL;
                    
                    count_digits(*int_value, digit_count);
                    convert_integer_to_ascii(*int_value, *digit_count, integer_to_string, base);
                    write(1, integer_to_string, *digit_count);

                    *character_count = *character_count + *digit_count;
                    
                    break;
                case 'f':
                    *double_value = va_arg(args_pointer, double);
                    
                    printf("%f", *double_value);
                    
                    (*character_count)++;
                    
                    break;
                case 'o':
                    *octal_value = va_arg(args_pointer, int);
                    
                    // int* digit_count; 
                    // char* integer_to_string;
                    
                    digit_count = malloc(sizeof(int));
                    integer_to_string = malloc(sizeof(char) * (*digit_count) + 1);
                    base = OCTAL;
                    
                    count_digits(*octal_value, digit_count);
                    convert_integer_to_ascii(*octal_value, *digit_count, integer_to_string, base);
                    write(1, integer_to_string, *digit_count);

                    *character_count = *character_count + *digit_count;
                    
                    break;
                case 's':
                    string_value = va_arg(args_pointer, char*);

                    if (string_value == NULL)
                    {
                        char* null_string_value = "(null)";      
                        int length = strlen(null_string_value);
                        
                        write(1, null_string_value, (length + 1));

                        *character_count = *character_count + length;
                    }
                    else
                    {
                        int length = strlen(string_value);
                        
                        write(1, string_value, (length + 1));
                        
                        *character_count = *character_count + length;
                    }
                    break;
                default:
                    write(1, pointer_value, 1);
                    (*character_count)++;
                    break;
                    
                return *character_count;
            }
        }
    }
    va_end(args_pointer); //Clean up argument list

    return *character_count;
}

// int main()
// {
//     my_printf("hello world.\n");
    
//     return 0;
// }