#include <stdio.h>

/**
 * main - Prints the numbers from 1 to 100, replacing multiples of 3
 * with Fizz, multiples of 5 with Buzz, and multiples of both with FizzBuzz
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n = 1;

	while (n <= 100)
	{
		if (n % 15 == 0)
			printf("FizzBuzz");
		else if (n % 3 == 0)
			printf("Fizz");
		else if (n % 5 == 0)
			printf("Buzz");
		else
			printf("%d", n);
		if (n < 100)
			printf(" ");
		n++;
	}
	printf("\n");
	return (0);
}
