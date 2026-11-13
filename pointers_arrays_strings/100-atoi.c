#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Description: counts every '-' sign before the first digit, then
 * reads the digits. The number is built as a negative value when
 * the result is negative, so INT_MIN works without overflow.
 *
 * Return: the converted integer, or 0 if there are no numbers
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int num;

	i = 0;
	sign = 1;
	num = 0;

	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		if (sign < 0)
			num = (num * 10) - (s[i] - '0');
		else
			num = (num * 10) + (s[i] - '0');
		i++;
	}

	return (num);
}
