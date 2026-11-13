#include "main.h"

/**
 * puts_half - prints the second half of a string, followed by a new line
 * @str: the string to print
 *
 * Description: if the length is odd, prints the last
 * (length + 1) / 2 characters
 */
void puts_half(char *str)
{
	int len;
	int i;

	len = 0;
	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
		i = len / 2;
	else
		i = len - (len + 1) / 2;

	while (i < len)
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
