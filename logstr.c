#include "main.h"

/**
 * logstr - writes the string str to stdout
 * @str: The string to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int logstr(char *str)
{

	return (write(1, str, count(str)));
}

/**
 * count - function to count the chars of string
 *
 * @str: string to count
 *
 * Return: on success returns the number of chars in a string,
 * on failure returns -1.
 */

int count(char *str)
{
	int length = 0;
	if (str == NULL)
		return (-1);
	if (!str)
		return (0);

	while (str[length])
		length++;
	return (length);
}
