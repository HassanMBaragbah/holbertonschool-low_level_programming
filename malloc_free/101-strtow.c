#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts the number of words in a string
 * @str: string to evaluate
 *
 * Return: number of words
 */
int count_words(char *str)
{
	int flag = 0, count = 0, i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			count++;
		}
		i++;
	}
	return (count);
}

/**
 * free_words - frees a 2D array of strings
 * @words: array of strings
 * @i: index up to which memory was allocated
 */
void free_words(char **words, int i)
{
	while (i >= 0)
	{
		free(words[i]);
		i--;
	}
	free(words);
}

/**
 * fetch_word - extracts a word from string and allocates memory for it
 * @str: source string
 * @i: pointer to the current index in str
 *
 * Return: pointer to allocated word, or NULL on failure
 */
static char *fetch_word(char *str, int *i)
{
	char *word;
	int j, len = 0, start;

	while (str[*i] == ' ')
		(*i)++;

	start = *i;
	while (str[*i] != ' ' && str[*i] != '\0')
	{
		len++;
		(*i)++;
	}

	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);

	for (j = 0; j < len; j++)
		word[j] = str[start + j];
	word[j] = '\0';

	return (word);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (words), or NULL if it fails
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, k, num_words;

	if (str == NULL || *str == '\0')
		return (NULL);

	num_words = count_words(str);
	if (num_words == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (num_words + 1));
	if (words == NULL)
		return (NULL);

	for (k = 0; k < num_words; k++)
	{
		words[k] = fetch_word(str, &i);
		if (words[k] == NULL)
		{
			free_words(words, k - 1);
			return (NULL);
		}
	}
	words[k] = NULL;

	return (words);
}
