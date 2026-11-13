#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a random valid password for 101-crackme
 *
 * Description: 101-crackme accepts a password whose bytes, summed as
 * their ASCII values, equal 2772 (0xad4). This program prints a
 * random string of printable characters whose values add up to 2772.
 *
 * Return: Always 0
 */
int main(void)
{
	long int target;
	int c;

	target = 2772;
	srand(time(NULL));

	while (target > 126)
	{
		c = 33 + rand() % (126 - 33 + 1);
		if (target - c < 33)
			c = 33 + rand() % 40;
		putchar(c);
		target -= c;
	}

	putchar((int)target);
	putchar('\n');

	return (0);
}
