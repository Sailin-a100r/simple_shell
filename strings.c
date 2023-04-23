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

/**
 * countchar - function that counts number of appearance of
 * a specefic char in a string
 *
 * @str: string to search
 * @c: character to count in the string
 *
 * Return: number of appearance of char in a string, -1 on error
 */

int countchar(char *str, char c)
{
	int length, i;

	/* NULL or empty string */
	if (!str)
		return (-1);

	i = length = 0;
	while (str[length])
	{
		if (str[length] == c)
			i++;
		length++;
	}
	return (i);
}

/**
 * _strcpy - function  that copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 *
 * @dest : pointer to destinstion of copied string;
 * @src : pointer to source string;
 *
 * Return: pointer to dest;
 */

char *_strcpy(char *dest, char *src)
{
	int n;
	int i;

	n = strlen(src);
	for (i = 0; i <= n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _strcmp - function that compares two strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 (if s1 matches s2),
 * positive value (if s1 greater than s2),
 * negative value (if s2 greater than s1).
 */
int _strcmp(char *s1, char *s2)
{
	int lenofs1;
	int lenofs2;
	int shorter;
	int i;

	lenofs1 = count(s1);
	lenofs2 = count(s2);
	shorter = lenofs1 > lenofs2 ? lenofs2 : lenofs1;
	if (!(lenofs1 == lenofs2))
	{
	return (lenofs1 - lenofs2);
	}
	else
	{
		for (i = 0; i < shorter; i++)
			if (!(s1[i] == s2[i]))
				return (s1[i] - s2[i]);
	}
	return (0);
}
