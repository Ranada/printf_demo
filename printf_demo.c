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

                    free(digit_count);
                    free(integer_to_string);

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

                    free(digit_count);
                    free(integer_to_string);

                    break;
                case 'p':
                    pointer_argument_value = va_arg(args_pointer, int*);

                    uintptr_t number = (uintptr_t)pointer_argument_value; // unitptr_t gives us 140701885900588 (decimal type number)
                    char buffer[2 + sizeof(number) * 2]; // Size of buffer: 18
                    int index = 0;
                    int size_buffer_to_fill = sizeof(buffer) - 2; // Size_buffer_to_fill: 16

                    /* Add '0' and 'x' to the first to positions in the string to indicate it is a hexadecimal value */
                    buffer[0] = '0';
                    buffer[1] = 'x';

                    for (index = 0; index < size_buffer_to_fill; index++)
                    {
                        buffer[index + 2] = "0123456789abcdef"[(number >> ((size_buffer_to_fill - 5 - index) * 4)) & 0xf]; // Shift 5 digits to offset for leading zeros in original address
                    }

                    write(1, buffer, sizeof(buffer) - 4);

                    *character_count = *character_count + sizeof(buffer) - 4;

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

                    free(digit_count);
                    free(integer_to_string);

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

                    free(digit_count);
                    free(integer_to_string);

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

    free(character_count);
    free(char_value);
    free(signed_decimal_value);
    free(unsigned_hexadecimal_value);
    free(unsigned_decimal_value);
    free(unsigned_octal_value);
    free(pointer_argument_value);
}

// int main()
// {
//     my_printf("hello world.\n");

//     return 0;
// }
