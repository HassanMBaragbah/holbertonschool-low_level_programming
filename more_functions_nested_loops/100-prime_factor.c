#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Finds and prints the largest prime factor of the number
 * 612852475143, followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long num = 612852475143;
	long factor = 2;

	while (num % factor == 0)
	{
		num /= factor;
	}

	factor = 3;
	while (factor * factor <= num)
	{
		if (num % factor == 0)
		{
			num /= factor;
		}
		else
		{
			factor += 2;
		}
	}

	printf("%ld\n", num);

	return (0);
}
