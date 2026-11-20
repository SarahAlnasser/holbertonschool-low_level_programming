#include <stdlib.h>
#include "main.h"

/**
 * count_words - counts the words in a string
 * @str: the string
 *
 * Return: number of words
 */
int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
	}

	return (count);
}

/**
 * free_words - frees an array of words
 * @words: the array
 * @n: number of words allocated so far
 *
 * Return: Nothing.
 */
void free_words(char **words, int n)
{
	int i;

	for (i = 0; i < n; i++)
		free(words[i]);
	free(words);
}

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: pointer to a NULL-terminated array of words,
 * or NULL if str is NULL, empty, has no words, or malloc fails
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, w = 0, len, k, nwords;

	if (str == NULL || *str == '\0')
		return (NULL);

	nwords = count_words(str);
	if (nwords == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (nwords + 1));
	if (words == NULL)
		return (NULL);

	while (w < nwords)
	{
		while (str[i] == ' ')
			i++;
		for (len = 0; str[i + len] != ' ' && str[i + len] != '\0'; len++)
			;
		words[w] = malloc(sizeof(char) * (len + 1));
		if (words[w] == NULL)
		{
			free_words(words, w);
			return (NULL);
		}
		for (k = 0; k < len; k++)
			words[w][k] = str[i + k];
		words[w][k] = '\0';
		i += len;
		w++;
	}
	words[w] = NULL;

	return (words);
}
