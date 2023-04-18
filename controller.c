#include "main.h"

/**
 * controller - function that executes the program given
 *
 * @path: path to the program to execute
 *
 * Return: 1 success , 0 otherwise.
 */

int controller(char *path)
{
	pid_t pid;
	int res;
	char *argvec[] = {NULL, NULL}; /* arguments vector */
	char *envec[] = {NULL}; /* environment vector */

	/* check for null and empty string */
	if (!path)
		return (0);

	argvec[0] = path;
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
		res = execve(path, argvec, envec);
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
