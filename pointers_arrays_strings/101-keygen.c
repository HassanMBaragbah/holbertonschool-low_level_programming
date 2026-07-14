#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a random valid password for 101-crackme.
 *
 * Return: Always 0.
 */
int main(void)
{
	int sum = 0;
	int remaining;
	char c;

	srand(time(NULL));

	while (sum < 2772)
	{
		c = rand() % 94 + 33;

		if ((sum + c) <= 2772)
		{
			remaining = 2772 - (sum + c);

			if (remaining == 0 || (remaining >= 33 && remaining <= 126))
			{
				sum += c;
				putchar(c);
			}
		}
	}

	return (0);
}