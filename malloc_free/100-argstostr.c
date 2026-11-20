#include <stdlib.h>
#include "main.h"

/**
 * argstostr - concatenates all the arguments of a program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to the new string (each argument followed by '\n'),
 * or NULL if ac == 0, av == NULL, or malloc fails
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k, total = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			total++;
		total++;
	}

	str = malloc(sizeof(char) * (total + 1));
	if (str == NULL)
		return (NULL);

	k = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			str[k++] = av[i][j];
		str[k++] = '\n';
	}
	str[k] = '\0';

	return (str);
}
