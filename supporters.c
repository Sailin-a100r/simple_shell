/**
 * get_envar - function that returns a pointer to a
 * specific environment variable
 *
 * @var: name of environment variable to get
 *
 * Return: pointer to the variable if found, NULL otherwise
 */

char *get_envar(char *var)
{
	char **envp;
	int i, j, chars;

	envp = environ;
	chars = count(var);
	i = 0;

	while (envp[i] != NULL)
	{
		for (j = 0; j <= chars; j++)
		{
			if (var[j] == envp[i][j])
				continue;
			if (j == chars)
				return (envp[i]);
			break;
		}
		i++;
	}
	return (NULL);
}
