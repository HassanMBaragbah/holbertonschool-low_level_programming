#include "main.h"

/**
 * print_number - Prints an integer.
 * @n: The integer to be printed.
 *
 * Description: Only uses _putchar to print, handles negative numbers
 * and doesn't use long or arrays.
 */
void print_number(int n)
{
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10 > 0)
	{
		print_number(num / 10);
	}
	_putchar((num % 10) + '0');
}
