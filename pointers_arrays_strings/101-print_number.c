#include "main.h"

/**
 * print_number - prints an integer using _putchar only
 * @n: the integer to print
 */
void print_number(int n)
{
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = -(unsigned int)n;
	}
	else
		num = n;

	if (num / 10 != 0)
		print_number(num / 10);

	_putchar((num % 10) + '0');
}
