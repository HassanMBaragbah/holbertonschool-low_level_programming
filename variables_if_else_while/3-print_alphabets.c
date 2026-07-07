#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints the alphabet in lowercase, and then in uppercase,
 * followed by a new line, using putchar only three times.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char low_alpha;
	char up_alpha;

	for (low_alpha = 'a'; low_alpha <= 'z'; low_alpha++)
	{
		putchar(low_alpha);
	}

	for (up_alpha = 'A'; up_alpha <= 'Z'; up_alpha++)
	{
		putchar(up_alpha);
	}
	putchar('\n');

	return (0);
}
