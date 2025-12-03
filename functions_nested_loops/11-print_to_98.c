#include "main.h"

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: the starting number
 *
 * Return: void
 */
void print_to_98(int n)
{
	int step;

	if (n <= 98)
		step = 1;
	else
		step = -1;

	while (n != 98)
	{
		if (n < 0)
		{
			_putchar('-');
			if (-n >= 10)
				_putchar((-n / 10) + '0');
			_putchar((-n % 10) + '0');
		}
		else
		{
			if (n >= 10)
				_putchar((n / 10) + '0');
			_putchar((n % 10) + '0');
		}
		_putchar(',');
		_putchar(' ');
		n += step;
	}

	_putchar('9');
	_putchar('8');
	_putchar('\n');
}
