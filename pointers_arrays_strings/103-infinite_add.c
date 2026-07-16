#include "main.h"

/**
 * rev_string - Reverses a string in place.
 * @s: The string to be reversed.
 *
 * Return: void.
 */
void rev_string(char *s)
{
	int i = 0;
	int j = 0;
	char temp;

	while (s[j] != '\0')
	{
		j++;
	}
	j--;

	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}

/**
 * infinite_add - Adds two numbers represented as strings.
 * @n1: The first number.
 * @n2: The second number.
 * @r: The buffer to store the result.
 * @size_r: The buffer size.
 *
 * Return: A pointer to the result, or 0 if result cannot be stored.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0;
	int i, j, k = 0;
	int sum, carry = 0;
	int val1, val2;

	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;

	i = len1 - 1;
	j = len2 - 1;

	if (len1 >= size_r || len2 >= size_r)
		return (0);

	while (i >= 0 || j >= 0 || carry > 0)
	{
		if (k >= size_r - 1)
			return (0);

		val1 = (i >= 0) ? (n1[i] - '0') : 0;
		val2 = (j >= 0) ? (n2[j] - '0') : 0;

		sum = val1 + val2 + carry;
		carry = sum / 10;
		r[k] = (sum % 10) + '0';

		k++;
		i--;
		j--;
	}

	r[k] = '\0';
	rev_string(r);

	return (r);
}
