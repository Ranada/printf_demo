#include "printf_demo.h"

int my_printf(const char* format, ...)
{
    va_list args_pointer; // Points to each agrument in the list
    va_start(args_pointer, format); // Looks at the first REQUIRED argument then finds and point to the first OPTIONAL argument
    
    character_count = malloc(sizeof(int));
    char_value = malloc(sizeof(int));
    signed_decimal_value = malloc(sizeof(int));
    unsigned_hexadecimal_value = malloc(sizeof(int));
    unsigned_decimal_value = malloc(sizeof(int));
    unsigned_octal_value = malloc(sizeof(int));
    pointer_argument_value = malloc(sizeof(int));

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
                    *signed_decimal_value = va_arg(args_pointer, int);
                    
                    digit_count = malloc(sizeof(int));
                    integer_to_string = malloc(sizeof(char) * (*digit_count) + 1);
                    base = DECIMAL;
                    
                    count_digits(*signed_decimal_value, digit_count);
                    convert_integer_to_ascii(*signed_decimal_value, *digit_count, integer_to_string, base);
                    write(1, integer_to_string, *digit_count);

                    *character_count = *character_count + *digit_count;
                    
                    break;
                case 'f':
                    *double_value = va_arg(args_pointer, double);
                    
                    printf("%f", *double_value);
                    
                    (*character_count)++;
                    
                    break;
                case 'o':
                    *unsigned_octal_value = va_arg(args_pointer, int);
                    
                    digit_count = malloc(sizeof(int));
                    integer_to_string = malloc(sizeof(char) * (*digit_count) + 1);
                    base = OCTAL;
                    
                    count_digits(*unsigned_octal_value, digit_count);
                    convert_integer_to_ascii(*unsigned_octal_value, *digit_count, integer_to_string, base);
                    write(1, integer_to_string, *digit_count);

                    *character_count = *character_count + *digit_count;
                    
                    break;
                case 'p':
                    pointer_argument_value = va_arg(args_pointer, int*);
                    
                    uintptr_t number = (uintptr_t)pointer_argument_value; // unitptr_t gives us 140701885900588 (decimal type number)
                    char buf[2 + sizeof(number) * 2]; 
                    size_t index = 0;

                    // printf("x: %lu\n", number);
                    // printf("size of x: %lu\n", sizeof(number));
                    // printf("buf: %lu\n", sizeof(buf));
                    // printf("i: %zu\n", index);


                    buf[0] = '0';
                    buf[1] = 'x';
                    
                    for (index = 0; index < sizeof(buf) - 2; index++) 
                    {
                        buf[index + 2] = "0123456789abcdef"[(number >> ((sizeof(buf) - 7 - index) * 4)) & 0xf];
                    }
                    
                    write(1, buf, sizeof(buf) - 4);

                    *character_count = *character_count + sizeof(buf) - 4;
                    
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
                case 'u':
                    *unsigned_decimal_value = va_arg(args_pointer, int);
                    
                    digit_count = malloc(sizeof(int));
                    integer_to_string = malloc(sizeof(char) * (*digit_count) + 1);
                    base = DECIMAL;
                    
                    count_digits(*unsigned_decimal_value, digit_count);
                    convert_integer_to_ascii(*unsigned_decimal_value, *digit_count, integer_to_string, base);
                    write(1, integer_to_string, *digit_count);

                    *character_count = *character_count + *digit_count;
                    
                    break;
                case 'x':
                    *unsigned_hexadecimal_value = va_arg(args_pointer, int);
                    
                    digit_count = malloc(sizeof(int));
                    integer_to_string = malloc(sizeof(char) * (*digit_count) + 1);
                    base = HEXADECIMAL;
                    
                    count_digits(*unsigned_hexadecimal_value, digit_count);
                    convert_integer_to_ascii(*unsigned_hexadecimal_value, *digit_count, integer_to_string, base);
                    write(1, integer_to_string, *digit_count + 1);

                    int count_characters = strlen(integer_to_string) + 1;

                    *character_count = count_characters;
                    
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