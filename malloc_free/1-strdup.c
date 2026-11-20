#include <stdlib.h>
#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated copy of a string
 * @str: the string to copy
 *
 * Return: pointer to the copy, or NULL if str is NULL or malloc fails
 */
char *_strdup(char *str)
{
	char *copy;
	unsigned int len, i;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len] != '\0'; len++)
		;

	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		copy[i] = str[i];

	return (copy);
}
