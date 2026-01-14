#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything based on a format string
 * @format: list of types (c: char, i: int, f: float, s: string)
 *
 * Only 2 ifs allowed total
 */
void print_all(const char * const format, ...)
{
    va_list args;
    unsigned int i = 0;
    int printed = 0;
    char *str;

    va_start(args, format);

    while (format && format[i])
    {
        if (printed)
            printf(", ");

        printed = 1;

        /* single if with void cast to avoid empty-body warning */
        if (format[i])
            (void)(
                format[i] == 'c' ? printf("%c", va_arg(args, int)) :
                format[i] == 'i' ? printf("%d", va_arg(args, int)) :
                format[i] == 'f' ? printf("%f", va_arg(args, double)) :
                format[i] == 's' ? ((str = va_arg(args, char *)) ? printf("%s", str) : printf("(nil)")) : 0
            );

        i++;
    }

    va_end(args);
    printf("\n");
}
