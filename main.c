#include "main.h"

/**
 * main - Entry point to the simple_shell
 *
 * Return: 0 Success
 */

int main(void)
{
	char *string, *line[1024];
	size_t n = 0;
	ssize_t characters = 0;

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
		logstr(string);
		logstr(" command executed\n");
	}
	free(*line);
	return (0);
}
