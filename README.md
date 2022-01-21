# printf_demo
printf_demo.c

Original author: Neil Ranada

This project aims to replicate the `printf()` C standard library function to understand its inner workings.

## How to install

- You can download the project folder and files manually to your computer or fork the Github repo at: 
https://github.com/Ranada/printf_demo
- Or through your terminal, clone this repository: `git clone https://github.com/Ranada/printf_demo`
- Go to the directory containing this project: `cd printf_demo`
- Check to see you have a GCC compiler installed: `gcc --version` (if not installed, consider using Homebrew method: https://formulae.brew.sh/formula/gcc)
- Compile automatically using the included makefile using `make` or manually `gcc -Wall -Wextra -Werror *.c -o run_test`

## How to test
- Use the `test_cases.c` file included with this project. Or add your C file with test functions and include `#include "printf_demo.h"` and `#include <stdio.h>` at the top of your file.
- Compile automatically using the included makefile using `make` or manually `gcc -Wall -Wextra -Werror *.c -o run_test`
- Run the program `./run_test`

Note: If you receive error messages for one or more of your test cases, comment out `//` the test function(s) in question and then try to compile with `make` and run the program again `./run_test`