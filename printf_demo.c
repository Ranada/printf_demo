#include "printf_demo.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int printf_demo(const char* format, ...)
{
    va_list args;
    int done;

    va_start(args, format);
    done = vfprintf(stdout, format, args);
    va_end(args);

    return done;
}

int main()
{
    printf_demo("Hello World.\n");

    return 0;
}