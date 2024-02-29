#include "main.h"

/**
 * is_digit - checks if a character is a digit
 * @c: the character to check
 *
 * Return: 1 if the character is a digit
*/
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * is_number - checks if a string is a number
 * @c: string to check
 *
 * Return: 0 if the string is a number
*/
int is_number(char *c)
{
	int what = 0;

	while (*c)
	{
		what += is_digit(*c);
		c++;
	}

	return (what);
}
