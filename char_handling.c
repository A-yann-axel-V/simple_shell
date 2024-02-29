#include "main.h"

/**
 * _strncmp - compares two strings on n characters
 * @s1: char*
 * @s2: char*
 * @n: number
 * Return: 0 (s1 == s2 || c == n) -1 otherwise
 */
int _strncmp(char *s1, char *s2, int n)
{
	int c = 0;

	while (((s1[c] != '\0') && (s2[c] != '\0')) && s1[c] == s2[c])
		c++;

	if (c == n)
		return (0);
	else if (s1[c] == s2[c])
		return (0);
	else
		return (-1);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string to duplicate
 * Return: pointer to duplicated string in allocated memory
 */
char *_strdup(char *str)
{
	char *duplicate_str;
	int i, len;

	if (str == NULL) /* validate str input */
		return (NULL);

	len = strlen(str) + 1;
	duplicate_str = malloc(sizeof(char) * len);
	if (duplicate_str == NULL)
		return (NULL);

	/**
	 * Iterate over each character in the string
	 * and copy it to the duplicate_str
	 */
	for (i = 0; i < len; i++)
		duplicate_str[i] = str[i];

	return (duplicate_str);
}

/**
 * _strcmp - compares two strings
 * @s1: char*
 * @s2: char*
 *
 * Return: 0 (s1 == s2) -1 otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int c = 0;

	while (((s1[c] != '\0') && (s2[c] != '\0')) && s1[c] == s2[c])
		c++;

	if (s1[c] == s2[c])
		return (0);
	else
		return (-1);
}

/**
 * _strcpy - function that copies the string pointed to by src,
 * including the terminating null byte (\0), to the buffer pointed to by dest
 * @dest: Destination parameter
 * @src: Source parameter
 * Return: desination as *char
 */

char *_strcpy(char *dest, char *src)
{
	int x;

	for (x = 0; src[x] != '\0'; x++)
		dest[x] = src[x];
	dest[x] = '\0';

	return (dest);
}

/**
 * _strlen - function that returns the length of a string
 * @s: parameter; pointer of the string
 * Return: Length of the string (int)
 */
int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}

	return (count);
}
