#include "main.h"

/**
 * print_number - Prints an integer using only _putchar
 * @n: The integer to print
 */
void print_number(int n)
{
	unsigned int num;
	unsigned int divisor = 1;

	if (n < 0)
	{
		_putchar('-');
		num = (unsigned int)(-(n + 1)) + 1;
	}
	else
	{
		num = n;
	}
	while (num / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		_putchar(num / divisor % 10 + '0');
		divisor /= 10;
	}
}
