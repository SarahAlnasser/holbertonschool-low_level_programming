#include "main.h"

/**
 * print_triangle - Prints a triangle, followed by a new line
 * @size: The size of the triangle
 */
void print_triangle(int size)
{
	int row = 1;
	int i;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}
	while (row <= size)
	{
		i = 0;
		while (i < size - row)
		{
			_putchar(' ');
			i++;
		}
		i = 0;
		while (i < row)
		{
			_putchar('#');
			i++;
		}
		_putchar('\n');
		row++;
	}
}
