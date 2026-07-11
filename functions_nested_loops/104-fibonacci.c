#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the first 98 Fibonacci numbers, starting with 1 and 2,
 * followed by a new line, without using arrays, pointers, or long long.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long f1 = 1, f2 = 2, next;
	unsigned long head1, head2, headN, tail1, tail2, tailN;
	unsigned long carry;
	int i;

	printf("%lu, %lu", f1, f2);
	for (i = 3; i <= 91; i++)
	{
		next = f1 + f2;
		printf(", %lu", next);
		f1 = f2;
		f2 = next;
	}
	head1 = f1 / 1000000000;
	tail1 = f1 % 1000000000;
	head2 = f2 / 1000000000;
	tail2 = f2 % 1000000000;
	for (i = 92; i <= 98; i++)
	{
		carry = (tail1 + tail2) / 1000000000;
		tailN = (tail1 + tail2) % 1000000000;
		headN = head1 + head2 + carry;
		printf(", %lu%09lu", headN, tailN);
		head1 = head2;
		tail1 = tail2;
		head2 = headN;
		tail2 = tailN;
	}
	printf("\n");
	return (0);
}
