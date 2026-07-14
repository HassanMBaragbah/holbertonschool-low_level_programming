#include "main.h"

/**
 * rot13 - Encodes a string using rot13.
 * @str: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *rot13(char *str)
{
	char alpha[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13_alpha[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i = 0;
	int j;

	while (str[i] != '\0')
	{
		j = 0;

		while (j < 52)
		{
			if (str[i] == alpha[j])
			{
				str[i] = rot13_alpha[j];
				break;
			}
			j++;
		}
		i++;
	}

	return (str);
}
