#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers
 * @argc: number of command line arguments
 * @argv: array containing the program command line arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argv[1] && argv[2])
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
		result = num1 * num2;
	}
	else
	{
		printf("Error\n");
		return (1);
	}

	printf("%d\n", result);
	return (0);
}
