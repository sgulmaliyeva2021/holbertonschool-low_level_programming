#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything based on a format string
 * @format: list of types of arguments passed
 *
 * Description: c = char, i = int, f = float, s = string
 * Ignored any other characters. Prints (nil) if string is NULL.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	int printed = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (printed)
			printf(", ");
		if (format[i] == 'c')
			printf("%c", va_arg(args, int)), printed = 1;
		if (format[i] == 'i')
			printf("%d", va_arg(args, int)), printed = 1;
		if (format[i] == 'f')
			printf("%f", va_arg(args, double)), printed = 1;
		if (format[i] == 's')
		{
			str = va_arg(args, char *);
			if (!str)
				str = "(nil)";
			printf("%s", str), printed = 1;
		}
		i++;
	}

	va_end(args);
	printf("\n");
}
