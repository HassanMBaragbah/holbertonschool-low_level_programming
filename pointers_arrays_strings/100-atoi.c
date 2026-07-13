#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The integer value of the converted string,
 *		 or 0 if no numbers are found.
 */
int _atoi(char *s)
{
	int i = 0;
	int res = 0;
	int sign = 1;
	int is_num = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (s[i] == '+')
		{
			continue;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			is_num = 1;
			res = (res * 10) - (s[i] - '0');
		}
		else if (is_num)
		{
			break;
		}
		i++;
	}

	if (sign > 0)
	{
		return (-res);
	}

	return (res);
}
