#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: starting number
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
		printf("%d, ", n);
		n += step;
	}
	printf("98\n");
}
