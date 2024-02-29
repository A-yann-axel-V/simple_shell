#include "main.h"

/**
 * print_string - Print string
 * @format: The string to print
 *
 * Return: The length of the output
 */
int print_string(const char *format)
{
	int len = 0;

	if (format == NULL)
		return (write(1, "", 1));

	while (format[len])
		len++;

	return (write(1, format, len));
}

/**
 * removeSpaces - removes spaces from a stirng
 * @strng: the string to remove in
 *
 * Return: new string
*/
char *removeSpaces(char *strng)
{
	int i = 0, j = 0;
	char *buf;

	if (strng == NULL)
		return (NULL);

	buf = malloc(strlen(strng) + 1);
	if (buf == NULL)
		return (NULL);

	while (strng[i + 1] != '\0')
	{
		if (strng[i] != ' ')
		{
			buf[j] = strng[i];
			j++;
		}
		i++;
	}
	buf[j] = '\0';

	if (strlen(buf) > 0)
		return (buf);

	return (NULL);
}
