#include "main.h"

/**
 * print_square - Prints a square, followed by a new line
 * @size: The size of the square
 */
void print_square(int size)
{
	int row = 0;
	int col;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			_putchar('#');
			col++;
		}
		_putchar('\n');
		row++;
	}
}
