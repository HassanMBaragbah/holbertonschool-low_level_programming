# Hello, World

This project marks the beginning of our low-level programming journey using the C language. It covers fundamental topics including the C compilation process, standard inputs and outputs, memory type sizes, and writing compliant shell scripts to automate basic C development pipeline phases.

## Learning Objectives

By the end of this project, you should be able to explain:
* Why C programming is awesome and who invented it (Dennis Ritchie).
* The four basic stages of `gcc` compilation: Preprocessing, Compilation, Assembly, and Linking.
* The entry point of a C program (`main` function) and how it influences return values.
* How to print data using `printf`, `puts`, and `putchar`.
* Using the `sizeof` operator to inspect data type sizes on a specific architecture.
* How to run and enforce the Betty coding style framework.

## Project Files Summary

| File Name | Description |
| :--- | :--- |
| `0-preprocessor` | A Bash script that runs a C file stored in `$CFILE` through the preprocessor stage and outputs the result to a file named `c`. |
| `1-compiler` | A Bash script that compiles a C file stored in `$CFILE` into an object file (without linking), producing a `.o` file. |
| `2-assembler` | A Bash script that generates the assembly code of a C file stored in `$CFILE` and saves it with a `.s` extension. |
| `3-name` | A Bash script that compiles a C file stored in `$CFILE` and creates an executable file named `cisfun`. |
| `4-puts.c` | A C program that prints exactly `"Programming is like building a multilingual puzzle`, followed by a new line, using the `puts` function. |


## Technical Requirements

* All C programs are compiled using: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
* All code is checked and validated against the `betty-style.pl` and `betty-doc.pl` linters.
* Shell scripts are exactly 2 lines long and begin with `#!/bin/bash`.
