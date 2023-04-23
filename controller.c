#include "main.h"

/**
 * controller - function that executes the program given
 *
 * @comline: command line to execute
 * @envp: environment variables vector
 * @dirarray: array of directories of path
 *
 * Return: 0 success , -1 otherwise.
 */

int controller(char *comline, char *envp[], char **dirarray)
{
	pid_t pid;
	int res;
	char *argvec[127]; /* max arguments vector */
	char *fullpath;

	set_argvec(comline, argvec);
	fullpath = search_path(dirarray, argvec[0]);

	/* no such program */
	if (!fullpath)
	{
		logstr("./hsh: No such file or directory\n");
		return (-1);
	}
	/* program found */
	argvec[0] = fullpath;
	pid = fork();
	if (pid == -1) /* fork failure */
	{
		perror("./hsh");
		return (-1);
	}
	if (pid == 0) /* for child process */
	{
		res = execve(argvec[0], argvec, envp);
		if (res == -1)
		{
			perror("./hsh");
			return (-1);
		}
		else
			return (0);
	}
	else /* for parent process */
	{
		wait(NULL); /* wait for termination signal */
		free(fullpath);
		return (0);
	}
}

/**
 * set_argvec - function to create the argument vector
 *
 * @com: the command given to the shell
 * @argvec: pointer to the argument vector to set
 *
 * Return: array of strings that is the argvec, or NULL on failure.
 */

char **set_argvec(char *com, char *argvec[])
{
	unsigned int size = 1;
	char *token;

	if (!com)
		return (NULL);
	token = strtok(com, " ");

	/* add pointer to the program */
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
