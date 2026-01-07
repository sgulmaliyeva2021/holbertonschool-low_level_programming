#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything based on a format string
 * @format: list of types (c = char, i = int, f = float, s = string)
 *
 * Prints a comma and space between arguments.
 * Prints (nil) if a string is NULL.
 * Ignores unknown format characters.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	char *sep = "";

	va_start(args, format);

	/* First top-level if: only enter if format is valid */
	if (format != NULL)
	{
		while (format[i] != '\0')
		{
			/* Second top-level if: handle allowed format characters */
			if (format[i] == 'c' || format[i] == 'i' ||
			    format[i] == 'f' || format[i] == 's')
			{
				if (format[i] == 'c')
					printf("%s%c", sep, va_arg(args, int));
				if (format[i] == 'i')
					printf("%s%d", sep, va_arg(args, int));
				if (format[i] == 'f')
					printf("%s%f", sep, va_arg(args, double));
				if (format[i] == 's')
				{
					str = va_arg(args, char *);
					if (str == NULL)
						printf("%s(nil)", sep);
					else
						printf("%s%s", sep, str);
				}
				sep = ", ";
			}
			i++;
		}
	}

	va_end(args);
	printf("\n");
}
