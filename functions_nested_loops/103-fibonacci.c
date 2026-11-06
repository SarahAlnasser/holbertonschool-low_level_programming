#include <stdio.h>

/**
 * main - Prints the sum of the even-valued Fibonacci terms
 * that do not exceed 4,000,000
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long a = 1;
	unsigned long b = 2;
	unsigned long next;
	unsigned long sum = 0;

	while (b <= 4000000)
	{
		if (b % 2 == 0)
			sum += b;
		next = a + b;
		a = b;
		b = next;
	}
	printf("%lu\n", sum);
	return (0);
}
