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

/**
 * free_array - function that frees the array of ointers given to it
 *
 * @array: array of pointers to free
 *
 * Return: pointer to the array after freeing it
 */

char **free_array(char **array)
{
	int i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
	return (array);
}
