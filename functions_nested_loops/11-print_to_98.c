#include "main.h"

/**
 * print_number - prints an integer using _putchar
 * @n: number to print
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		if (n <= -10)
			print_number(-(n / 10));
		_putchar('0' - (n % 10));
	}
	else
	{
		if (n >= 10)
			print_number(n / 10);
		_putchar((n % 10) + '0');
	}
}

/**
 * print_to_98 - prints all numbers from n to 98
 * @n: starting number
 */
void print_to_98(int n)
{
	int step;

	if (n <= 98)
		step = 1;
	else
		step =
