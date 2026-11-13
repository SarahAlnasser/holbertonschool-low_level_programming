#include "main.h"

/**
 * _len - returns the length of a string
 * @s: the string
 *
 * Return: the length of s
 */
int _len(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * infinite_add - adds two numbers stored as strings
 * @n1: the first number
 * @n2: the second number
 * @r: the buffer to store the result
 * @size_r: the size of the buffer r
 *
 * Return: a pointer to r, or 0 if the result cannot fit in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i1;
	int i2;
	int carry;
	int sum;
	int pos;
	int k;
	char tmp;

	i1 = _len(n1) - 1;
	i2 = _len(n2) - 1;
	carry = 0;
	pos = 0;

	while (i1 >= 0 || i2 >= 0 || carry > 0)
	{
		sum = carry;
		if (i1 >= 0)
			sum += n1[i1--] - '0';
		if (i2 >= 0)
			sum += n2[i2--] - '0';
		carry = sum / 10;
		if (pos >= size_r - 1)
			return (0);
		r[pos++] = (sum % 10) + '0';
	}

	r[pos] = '\0';

	for (k = 0; k < pos / 2; k++)
	{
		tmp = r[k];
		r[k] = r[pos - 1 - k];
		r[pos - 1 - k] = tmp;
	}

	return (r);
}
