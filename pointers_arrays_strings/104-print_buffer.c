#include "main.h"
#include <stdio.h>

/**
 * print_hex - Prints the hexadecimal representation of 10 bytes.
 * @b: The buffer.
 * @offset: The current position in the buffer.
 * @size: The size of the buffer.
 */
void print_hex(char *b, int offset, int size)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (i + offset < size)
		{
			printf("%02x", b[offset + i]);
		}
		else
		{
			printf("  ");
		}

		if (i % 2 != 0)
		{
			printf(" ");
		}
	}
}

/**
 * print_ascii - Prints the ASCII representation of 10 bytes.
 * @b: The buffer.
 * @offset: The current position in the buffer.
 * @size: The size of the buffer.
 */
void print_ascii(char *b, int offset, int size)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (i + offset >= size)
		{
			break;
		}

		if (b[offset + i] >= 32 && b[offset + i] <= 126)
		{
			printf("%c", b[offset + i]);
		}
		else
		{
			printf(".");
		}
	}
}

/**
 * print_buffer - Prints a buffer in a specific format.
 * @b: The buffer to print.
 * @size: The size of the buffer.
 */
void print_buffer(char *b, int size)
{
	int offset;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (offset = 0; offset < size; offset += 10)
	{
		printf("%08x: ", offset);
		print_hex(b, offset, size);
		print_ascii(b, offset, size);
		printf("\n");
	}
}
