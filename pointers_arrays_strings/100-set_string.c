#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char.
 * @s: The double pointer to modify.
 * @to: The pointer containing the target address.
 *
 * Return: void.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
