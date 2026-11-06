#include <stdio.h>

/**
 * main - Finds and prints the largest prime factor of 612852475143
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long n = 612852475143;
	long factor = 2;

	while (factor * factor <= n)
	{
		if (n % factor == 0)
			n /= factor;
		else
			factor++;
	}
	printf("%ld\n", n);
	return (0);
}
