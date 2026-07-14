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
	char c;

	srand(time(NULL));

	while (sum < (2772 - 126))
	{
		c = rand() % 94 + 33;
		sum += c;
		putchar(c);
	}

	putchar(2772 - sum);

	return (0);
}