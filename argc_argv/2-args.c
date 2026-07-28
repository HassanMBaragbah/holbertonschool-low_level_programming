#include <stdio.h>

/**
 *
 *
 *
 *
 *
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argv[1] && argv[2])
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
		result = num1 * num2;
		printf("%d\n", result);
	}
	else
	{
		printf("Error\n");
		return (1);
	}

	return (0);
}
