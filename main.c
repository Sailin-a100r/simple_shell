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
	char *string, *line[] = {NULL}, *dirarray[20], path[300];
	size_t n = 0, quit = 0;
	ssize_t characters = 0;
	char delim[] = "\n";

	/* for unused warnings */
	argc = argc;
	argv = argv;

	/* create the path array */
	get_path(path);
	get_dirarray(path, dirarray);
	while (!quit)
	{
		/* prompt and wait for inpt */
		logstr("$ ");
		characters = getline(line, &n, stdin);
		/* Handle EOF (Ctrl+D) condition */
		if (characters == -1)
			return (-1);
		/* getrid of new line character */
		string = strtok(*line, delim);
		/* delegate to controller */
		if (!string)
			continue;
		controller(string, envp, dirarray, &quit);
	}
	free(*line);
	return (0);
}
