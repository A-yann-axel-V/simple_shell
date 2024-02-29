#include "main.h"

/**
 * aux_itoa - Convert integer to char
 * @i: The integer to convert
 *
 * Return: Char *
 */
char *aux_itoa(int i)
{
	char *ptr;
	int count = 0, n = i, x = 1, k;

	while (n != 0)
	{
		count++;
		n /= 10;
		x *= 10;
	}

	x /= 10;
	ptr = (char *)malloc((count + 1) * sizeof(char));
	if (ptr == NULL)
		exit(1);

	for (k = count - 1; k >= 0; k--)
	{
		if (i < 10)
			ptr[k] = i + '0';
		else
			ptr[k] = (i % x) + '0';
		i /= 10;
		x /= 10;
	}
	ptr[count] = '\0';
	return (ptr);
}
