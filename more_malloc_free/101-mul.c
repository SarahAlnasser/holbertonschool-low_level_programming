#include <stdlib.h>
#include "main.h"

/**
 * error_exit - prints Error and exits with status 98
 *
 * Return: Nothing.
 */
void error_exit(void)
{
	char *msg = "Error\n";

	while (*msg)
		_putchar(*msg++);
	exit(98);
}

/**
 * check_digits - checks that a string is only digits and gets its length
 * @s: the string to check
 *
 * Return: length of s (exits with 98 if s has a non-digit or is empty)
 */
int check_digits(char *s)
{
	int len = 0;

	if (s[0] == '\0')
		error_exit();

	while (s[len] != '\0')
	{
		if (s[len] < '0' || s[len] > '9')
			error_exit();
		len++;
	}

	return (len);
}

/**
 * print_result - prints the result array without leading zeros
 * @res: array of digits (0-9)
 * @len: length of the array
 *
 * Return: Nothing.
 */
void print_result(int *res, int len)
{
	int i = 0;

	while (i < len - 1 && res[i] == 0)
		i++;

	for (; i < len; i++)
		_putchar(res[i] + '0');
	_putchar('\n');
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success (exits with 98 on error)
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, total, i, j, n1, n2, sum;
	int *res;

	if (argc != 3)
		error_exit();

	s1 = argv[1];
	s2 = argv[2];
	len1 = check_digits(s1);
	len2 = check_digits(s2);
	total = len1 + len2;

	res = malloc(sizeof(int) * total);
	if (res == NULL)
		error_exit();
	for (i = 0; i < total; i++)
		res[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = s1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = s2[j] - '0';
			sum = n1 * n2 + res[i + j + 1];
			res[i + j + 1] = sum % 10;
			res[i + j] += sum / 10;
		}
	}

	print_result(res, total);
	free(res);
	return (0);
}
