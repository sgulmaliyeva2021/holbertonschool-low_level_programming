#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <sys/types.h>

/* Prototype of read_textfile */
ssize_t read_textfile(const char *filename, size_t letters);

int create_file(const char *filename, char *text_content);


/* Prototype of _putchar (provided by Holberton) */
int _putchar(char c);

#endif /* MAIN_H */
