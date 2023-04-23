#include "main.h"

/**
 * _strcat - function that concatenates two strings
 *
 * @dest: destination string to append to
 * @src: source string to append
 *
 * Return: a pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int j;
	int lenofd;

	j = 0;
	i = count(dest);
	lenofd = count(src) + count(dest);
	for (; i < lenofd; i++)
	{
		dest[i] = src[j];
		j++;
	}
	return (dest);
}
