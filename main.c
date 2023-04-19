#include "main.h"

/**
 * main - Entry point to the simple_shell
 *
 * @argc: number of arguments given to program
 * @argv: array of pointers to arguments as strings
 * @envp: array of pointers to environment varaibles
 *
 * Return: 0 Success
 */

int main(int argc, char *argv[], char *envp[])
{
	char *string, *line[100];
	size_t n = 0;
	ssize_t characters = 0;

	/* for unused warnings */
	argc = argc;
	argv = argv;

	while (1)
	{
		/* prompt and wait for inpt */
		logstr("$ ");
		characters = getline(line, &n, stdin);

		/* Handle EOF (Ctrl+D) condition */
		if (characters == -1)
			return (-1);

		/* getrid of new line character */
		string = strtok(*line, "\n");

		/* delegate to controller */
		if (!string)
			continue;
		controller(string, envp);
	}
	free(*line);
	return (0);
}
