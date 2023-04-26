#include "main.h"

/**
 * controller - function that executes the program given
 *
 * @comline: command line to execute
 * @envp: poiner to environment variables vector
 * @dirarray: array of directories of path
 * @exit: pointer to exit signal
 *
 * Return: 0 success , -1 otherwise.
 */

int controller(char *comline, char *envp[], char **dirarray, size_t *quit)
{
	int res = 0;
	char *argvec[127]; /* max arguments vector */
	char fullpath[256] = "";

	set_argvec(comline, argvec);
	if (_strcmp(argvec[0], "exit") == 0)
	{
		*quit = 1;
		return (-1);
	}
	else if (argvec[0][0] == '/' || argvec[0][0] == '.')
	{
		res = start_process(argvec, envp);
		return (res);
	}
	search_path(dirarray, argvec[0], fullpath);

	/* no such program */
	if (fullpath[0] != '/')
	{
		logstr("./hsh: No such file or directory\n");
		return (-1);
	}
	/* program found */
	argvec[0] = fullpath;

	res = start_process(argvec, envp);
	return (res);
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

/**
 * start_process - function that creates a child process
 *
 * @argvec: array of the path and arguments of the program
 * @envp: pointer to environment variables
 *
 * Return: 0 on success, -1 on errror
 */

int start_process(char **argvec, char **envp)
{
	pid_t pid;
	int res;

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
		return (0);
	}
	return (0);
}
