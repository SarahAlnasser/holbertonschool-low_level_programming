#include "main.h"

/**
 * more_numbers - Prints the numbers from 0 to 14, 10 times
 */
void more_numbers(void)
{
	int i = 0;
	int n;

	while (i < 10)
	{
		n = 0;
		while (n <= 14)
		{
			if (n >= 10)
				_putchar(n / 10 + '0');
			_putchar(n % 10 + '0');
			n++;
		}
		_putchar('\n');
		i++;
	}
}
