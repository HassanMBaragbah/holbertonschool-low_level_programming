# C - File I/O

## Description
This project covers low-level File Input/Output (I/O) system calls in C, focusing on file descriptors, creating, opening, reading, writing, and closing files. It delves into handling POSIX standard file descriptors, managing file permissions, and using system call flags (`O_RDONLY`, `O_WRONLY`, `O_CREAT`, `O_TRUNC`, `O_APPEND`).

## Tasks

| Task | File | Description | Status |
| :---: | --- | --- | --- |
| **0** | `0-read_textfile.c` | Reads a text file and prints it to POSIX standard output. | <ul><li>[x] Completed</li></ul> |
| **1** | `1-create_file.c` | Creates a file with permissions `rw-------` and writes text content to it. | <ul><li>[x] Completed</li></ul> |
| **2** | `2-append_text_to_file.c` | Appends text at the end of an existing file without creating it if non-existent. | <ul><li>[ ] In Progress</li></ul> |
| **3** | `3-cp.c` | Copies the content of a file to another file with precise error handling and exit codes. | <ul><li>[ ] In Progress</li></ul> |
| **100** | `100-elf_header.c` | Displays information contained in the ELF header at the start of an ELF file like `readelf -h`. | <ul><li>[ ] In Progress</li></ul> |

## Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:
- How to look for the right source of information online.
- How to create, open, close, read, and write files using system calls.
- What file descriptors are and the 3 standard file descriptors (`STDIN_FILENO`, `STDOUT_FILENO`, `STDERR_FILENO`).
- How to use I/O system calls `open`, `close`, `read`, and `write`.
- What the flags `O_RDONLY`, `O_WRONLY`, `O_RDWR`, `O_CREAT`, `O_TRUNC`, and `O_APPEND` are and how to use them.
- What file permissions are and how to set them when creating a file with `open`.
- What a system call is and the difference between a function and a system call.

## Requirements
- Allowed editors: `vi`, `vim`, `emacs`.
- All files will be compiled on **Ubuntu 20.04 LTS** using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- All files should end with a new line.
- A `README.md` file at the root of the folder is mandatory.
- Code must use the **Betty style** (checked using `betty-style.pl` and `betty-doc.pl`).
- Global variables are not allowed.
- Maximum of 5 functions per file.
- Allowed C standard library functions: `malloc`, `free`, and `exit`.
- Allowed syscalls: `read`, `write`, `open`, `close`.
- Include guards are required for all header files (`main.h`).