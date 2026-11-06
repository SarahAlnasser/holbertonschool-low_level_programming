#include <stdio.h>

/**
 * print_split - Prints a number stored in two halves
 * @high: The digits above the lower ten digits
 * @low: The lower ten digits
 */
void print_split(unsigned long high, unsigned long low)
{
	if (high > 0)
		printf("%lu%010lu", high, low);
	else
		printf("%lu", low);
}

/**
 * main - Prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Description: Each number is kept in two halves (high and low)
 * so values larger than an unsigned long can still be printed.
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long split = 10000000000;
	unsigned long a_high = 0, a_low = 1;
	unsigned long b_high = 0, b_low = 2;
	unsigned long n_high, n_low;
	int i;

	printf("%lu, %lu", a_low, b_low);
	for (i = 3; i <= 98; i++)
	{
		n_low = a_low + b_low;
		n_high = a_high + b_high + n_low / split;
		n_low = n_low % split;
		printf(", ");
		print_split(n_high, n_low);
		a_high = b_high;
		a_low = b_low;
		b_high = n_high;
		b_low = n_low;
	}
	printf("\n");
	return (0);
}
