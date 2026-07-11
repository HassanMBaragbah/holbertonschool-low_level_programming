#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Finds and prints the sum of the even-valued terms
 * in the Fibonacci sequence whose values do not exceed 4,000,000,
 * followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long fib1 = 1, fib2 = 2, next = 0;
	unsigned long sum = 0;

	sum += fib2;

	while (next <= 4000000)
	{
		next = fib1 + fib2;

		if (next > 4000000)
			break;

		if (next % 2 == 0)
		{
			sum += next;
		}

		fib1 = fib2;
		fib2 = next;
	}

	printf("%lu\n", sum);

	return (0);
}
