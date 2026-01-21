# File I/O - Holberton Project

## Description

This project implements basic file I/O operations in C using only allowed system calls (`read`, `write`, `open`, `close`) and standard library functions (`malloc`, `free`, `exit`).  

It includes:

- `0-read_textfile.c` → reads a file and prints to standard output.
- `1-create_file.c` → creates a file and writes text to it.
- `2-append_text_to_file.c` → appends text at the end of a file.
- `3-cp.c` → copies the content of one file to another.

All code follows **Betty style** and works on **Ubuntu 20.04 LTS**.

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-read_textfile.c -o read_textfile
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-create_file.c -o create_file
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-append_text_to_file.c -o append_text_to_file
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-cp.c -o cp
