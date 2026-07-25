#include "main.h"
#include <stdlib.h>

/**
 * _strlen - Computes the length of a string.
 * @s: The string to measure.
 *
 * Return: Length of the string.
 */
int _strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * is_digit - Checks if a string consists entirely of digits.
 * @s: The string to validate.
 *
 * Return: 1 if all characters are digits, 0 otherwise.
 */
int is_digit(char *s)
{
	int i;

	i = 0;
	if (s == NULL || s[0] == '\0')
		return (0);

	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * print_error - Prints "Error\n", frees optional ptr, and exits with 98.
 * @ptr: Memory pointer to free before exiting (can be NULL).
 */
void print_error(void *ptr)
{
	char *err;
	int i;

	err = "Error\n";
	if (ptr != NULL)
		free(ptr);

	i = 0;
	while (err[i] != '\0')
	{
		_putchar(err[i]);
		i++;
	}
	exit(98);
}

/**
 * multiply - Performs long multiplication on two numeric strings.
 * @n1: First number string.
 * @n2: Second number string.
 * @len1: Length of n1.
 * @len2: Length of n2.
 */
void multiply(char *n1, char *n2, int len1, int len2)
{
	int total_len, i, j, start;
	int digit1, digit2, sum;
	int *result;

	total_len = len1 + len2;
	result = malloc(sizeof(int) * total_len);
	if (result == NULL)
		print_error(NULL);

	for (i = 0; i < total_len; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		digit1 = n1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = n2[j] - '0';
			sum = (digit1 * digit2) + result[i + j + 1];
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	start = 0;
	while (start < total_len - 1 && result[start] == 0)
		start++;

	for (i = start; i < total_len; i++)
		_putchar(result[i] + '0');

	_putchar('\n');
	free(result);
}

/**
 * main - Multiplies two positive numbers passed as CLI arguments.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: Always 0 on success.
 */
int main(int argc, char *argv[])
{
	int len1, len2;

	if (argc != 3)
		print_error(NULL);

	if (!is_digit(argv[1]) || !is_digit(argv[2]))
		print_error(NULL);

	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);

	multiply(argv[1], argv[2], len1, len2);

	return (0);
}
