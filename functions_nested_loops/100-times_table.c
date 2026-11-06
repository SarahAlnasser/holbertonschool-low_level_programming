#include "main.h"

/**
 * print_times_table - Prints the n times table, starting with 0
 * @n: The size of the table, from 0 to 15
 */
void print_times_table(int n)
{
	int row, col, product;

	if (n < 0 || n > 15)
		return;
	for (row = 0; row <= n; row++)
	{
		_putchar('0');
		for (col = 1; col <= n; col++)
		{
			product = row * col;
			_putchar(',');
			_putchar(' ');
			if (product < 100)
				_putchar(' ');
			if (product < 10)
				_putchar(' ');
			if (product >= 100)
				_putchar(product / 100 + '0');
			if (product >= 10)
				_putchar(product / 10 % 10 + '0');
			_putchar(product % 10 + '0');
		}
		_putchar('\n');
	}
}
