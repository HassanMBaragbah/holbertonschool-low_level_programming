# More Functions and Nested Loops

## Description
This project focuses on deepening the understanding of control structures, nested loops, and custom function definitions in C programming. It emphasizes character processing using ASCII values and modular code architecture without relying on the C standard library.

## Learning Objectives
* Understand how to construct and optimize nested loops.
* Define and implement functions, distinguishing between declaration and definition.
* Utilize function prototypes and construct robust header (`.h`) files.
* Grasp variable scope and compiler configurations (`-Wall -Wextra -Werror -pedantic -std=gnu89`).

## Requirements
* **Allowed Editors:** vi, vim, emacs.
* **Compilation:** Ubuntu 20.04 LTS via `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`.
* **Style Guide:** Strict adherence to Betty style (`betty-style.pl` and `betty-doc.pl`).
* **Constraints:** No global variables, maximum of 5 functions per file, and standard library functions (like `printf`, `puts`) are strictly forbidden unless specified. The system utilizes a custom `_putchar` function.

## Header File
All function prototypes, including `_putchar`, must be enclosed within `main.h`.

## Tasks

| Task | File | Description | Status |
| :---: | --- | --- | --- |
| **0** | `0-isupper.c` | Checks if a character is uppercase. Returns 1 if true, 0 otherwise. | <ul><li>[x] Completed</li></ul> |
| **1** | `1-isdigit.c` | Checks for a digit (0 through 9). Returns 1 if true, 0 otherwise. | <ul><li>[x] Completed</li></ul> |
| **2** | `2-mul.c` | Multiplies two integers and returns the result. | <ul><li>[x] Completed</li></ul> |
| **3** | `3-print_numbers.c` | Prints the numbers from 0 to 9, followed by a new line, using `_putchar` only twice. | <ul><li>[x] Completed</li></ul> |
| **4** | `4-print_most_numbers.c` | Prints the numbers from 0 to 9 (excluding 2 and 4), followed by a new line, using `_putchar` only twice. | <ul><li>[x] Completed</li></ul> |
| **5** | `5-more_numbers.c` | Prints 10 times the numbers from 0 to 14, followed by a new line, using `_putchar` only three times. | <ul><li>[x] Completed</li></ul> |
| **6** | `6-print_line.c` | Draws a straight line in the terminal using the character `_`, followed by a new line. | <ul><li>[x] Completed</li></ul> |
| **7** | `7-print_diagonal.c` | Draws a diagonal line on the terminal using spaces and the `\` character. | <ul><li>[x] Completed</li></ul> |
| **8** | `8-print_square.c` | Prints a square of a given size using the `#` character, followed by a new line. | <ul><li>[x] Completed</li></ul> |
| **9** | `9-fizz_buzz.c` | Prints numbers from 1 to 100 with 'Fizz' for multiples of 3, 'Buzz' for multiples of 5, and 'FizzBuzz' for both. | <ul><li>[x] Completed</li></ul> |
| **10** | `10-print_triangle.c` | Prints a triangle of a given size using the `#` character, followed by a new line. | <ul><li>[x] Completed</li></ul> |
| **100** | `100-prime_factor.c` | Finds and prints the largest prime factor of the number 612852475143. | <ul><li>[x] Completed</li></ul> |
| **101** | `101-print_number.c` | Prints an integer using recursion and handling `INT_MIN` safely without using `long`. | <ul><li>[x] Completed</li></ul> |