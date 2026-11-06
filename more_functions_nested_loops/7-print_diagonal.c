#include "main.h"

/**
 * print_diagonal - Draws a diagonal line in the terminal
 * @n: The number of times the character \ should be printed
 */
void print_diagonal(int n)
{
	int line = 0;
	int space;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}
	while (line < n)
	{
		space = 0;
		while (space < line)
		{
			_putchar(' ');
			space++;
		}
		_putchar('\\');
		_putchar('\n');
		line++;
	}
}
