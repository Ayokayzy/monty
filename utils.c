#include "monty.h"

/**
 * is_int - checks if a character is an integer
 * @s: the charcter to be checked
 * Return: 0 if the character is an integer else 1
 */

int is_int(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 48 || s[i] < 58)
		{
			return (1);
		}
	}
	return (0);
}
