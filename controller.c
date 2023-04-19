#include "main.h"

/**
 * controller - function that executes the program given
 *
 * @path: path to the program to execute
 * @envp: environment variables vector
 *
 * Return: 1 success , 0 otherwise.
 */

int controller(char *comline, char *envp[])
{
	pid_t pid;
	int res;
	char *argvec[127] ; /* arguments vector */
	/*char **envec = {NULL};*/ /* environment vector */

	/* create a duplicate */
	pid = fork();

	if (pid == -1)
	{
		perror("./hsh");
		return (0);
	}
	/* for child program */
	else if (pid == 0)
	{
		set_argvec(comline, argvec);
		res = execve(argvec[0], argvec, envp);
		if (res == -1)
		{
			perror("./hsh");
			return (0);
		}
		else
			return (1);
	}
	/* for parent program */
	else
	{
		wait(NULL); /* wait for termination signal */
		return (1);
	}
}

/**
 * set_argvec - function to create the argument vector
 *
 * @com - the command given to the shell
 *
 * Return: array of strings that is the argvec, or NULL on failure.
 */

char **set_argvec(char *com, char *argvec[])
{
	unsigned int size = 1;
	char *token;

	if (!com)
	{
		return (NULL);
	}
	token = strtok(com, " ");

	/* add pointer to the path */
	argvec[0] = token;

	/* add other arguments if found */
	while (token)
	{
		token = strtok(NULL, " ");
		argvec[size] = token;
		size = size + 1;
	}
	return (argvec);
}

/**
 * _realloc - function that reallocates a memory block using malloc and free
 *
 * @ptr: pointer to old memory
 * @old_size: size of old memory
 * @new_size: size of new memory
 *
 * Return: pointer to the new memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *newptr, *oldptr;
	int i, old, new;

	old = old_size;
	new = new_size;
	if (ptr == NULL)
	{
		newptr = malloc(new_size);
		if (newptr == NULL)
			return (NULL);
		return ((void *) newptr);
	}
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
	{
		return (ptr);
	}
	else if (new_size > old_size)
	{
		newptr = malloc(new_size);
		if (newptr == NULL)
			return (NULL);
		oldptr = (char *) ptr;
		for (i = 0; i < old; i++)
		{
			newptr[i] = oldptr[i];
		}
		free(ptr);
		return ((void *) newptr);
	}
	else if (new_size < old_size)
	{
		newptr = malloc(new_size);
		if (newptr == NULL)
			return (NULL);
		oldptr = (char *) ptr;
		for (i = 0; i < new; i++)
		{
			newptr[i] = oldptr[i];
		}
		free(ptr);
		return ((void *) newptr);
	}
	return (ptr);
}
