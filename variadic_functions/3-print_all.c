#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything based on a format string
 * @format: list of types (c: char, i: int, f: float, s: string)
 *
 * Allowed: max 2 ifs, no else if
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

        /* Single if for all types */
        if (format[i] == 'c' || format[i] == 'i' || format[i] == 'f' || format[i] == 's')
        {
            printed = 1;

            format[i] == 'c' && printf("%c", va_arg(args, int));
            format[i] == 'i' && printf("%d", va_arg(args, int));
            format[i] == 'f' && printf("%f", va_arg(args, double));
            format[i] == 's' && ((str = va_arg(args, char *)) ? printf("%s", str) : printf("(nil)"));
        }
        i++;
    }

    va_end(args);
    printf("\n");
}
