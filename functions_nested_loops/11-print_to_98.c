#include "main.h"

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: the starting number
 *
 * Return: void
 */
void print_to_98(int n)
{
	int i;

	if (n <= 98)
	{
		for (i = n; i <= 98; i++)
		{
			if (i != 98)
			{
				_putchar(i / 10 + '0');
				_putchar(i % 10 + '0');
				_putchar(',');
				_putchar(' ');
			}
			else
			{
				if (i < 10 && i >= 0)
					_putchar(i + '0');
				else if (i < 0)
				{
					_putchar('-');
					_putchar(-i / 10 + '0');
					_putchar(-i % 10 + '0');
				}
				else
				{
					_putchar(i / 10 + '0');
					_putchar(i % 10 + '0');
				}
			}
		}
	}
	else
	{
		for (i = n; i >= 98; i--)
		{
			if (i != 98)
			{
				if (i >= 0)
				{
					_putchar(i / 10 + '0');
					_putchar(i % 10 + '0');
				}
				else
				{
					_putchar('-');
					_putchar(-i / 10 + '0');
					_putchar(-i % 10 + '0');
				}
				_putchar(',');
				_putchar(' ');
			}
			else
			{
				_putchar('9');
				_putchar('8');
			}
		}
	}
	_putchar('\n');
}
