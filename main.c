#include "main.h"

/**
 * main - Entry point to the simple shell
 *
 * @argc: number of command line arguuments
 * @argv: array of strings of command line arguments
 *
 * Return: 0 Success
 */

int main(void)
{
	char *string, *line[1024];
	size_t n = 0;

	while (1)
	{
		/* prompt and wait for inpt */
		logstr("$ ");
		getline(line, &n, stdin);

		/* getrid of new line character */
		string = strtok(*line, "\n");
		printf("Command %s executed\n", string);
		logstr("Command done!\n");
	}
	free(*line);
	return (0);
}
