#include "main.h"

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

/**
 * get_dirarray - function that returns an array of directories of $PATH
 *
 * @path: pointer to copy of $PATH
 * @dirarray: array of pointers to path directories
 *
 * Return: array of strings of directories of $PATH
 */
char **get_dirarray(char *path, char **dirarray)
{
	char *dirname;
	int dircount, index;

	/* count number of directories in the path */
	dircount = countchar(path, ':') + 1;
	/* tokenise the directories */
	dirname = strtok(path, "=");

	/* fill the array with pointers to dirs */
	index = 0;
	while (index <= dircount)
	{
		dirname = strtok(NULL, ":");
		dirarray[index] = dirname;
		index = index + 1;
	}
	return (dirarray);
}

/**
 * get_path - function that returns a pointer to a copy of $PATH
 *
 * @path: string to hold a copy of the path
 *
 * Return: pointer to a copied string of $PATH
 */
char *get_path(char *path)
{
	char *pathpt;

	/* pointer to the path environment variable */
	pathpt = get_envar("PATH");

	/* copy the PATH into path */
	if (path) /* success */
	{
		_strcpy(path, pathpt);
		return (path);
	}
	return (NULL); /* failure */
}

/**
 * search_dir - function that searches the given directory
 * for a given file name
 *
 * @dirname: the name of the directory to search
 * @filename: the name of the file to look for
 * @filepath: fullpath of file if found
 *
 * Return: On success returns full path to the file
 * On failure returns NULL
 */
char *search_dir(char *dirname, char *filename, char *filepath)
{
	DIR *dir; /* pointer to open directory */
	dirent_t *entity; /* pointer to the structure returned */

	dir = opendir(dirname);
	if (dir == NULL)
		return (NULL);

	entity = readdir(dir);
	while (entity)
	{
		if (_strcmp(entity->d_name, filename) == 0)
		{ /* success */
			_strcpy(filepath, dirname);
			_strcat(filepath, "//");
			_strcat(filepath, filename);
			closedir(dir);
			return (filepath);
		}
		entity = readdir(dir);
	}
	/* no match */
	closedir(dir);
	return (NULL);
}

/**
 * search_path - function that searches the path directories
 * for a specefic program name
 *
 * @dirarray: array of path directories
 * @filename: name of the program to look for
 * @filepath: fullpath to the file if found
 *
 * Return: Onsuccess return the full path of the program,
 * Onfailure return NULL
 */

char *search_path(char **dirarray, char *filename, char *filepath)
{
	int index = 0;

	while (dirarray[index])
	{
		search_dir(dirarray[index], filename, filepath);
		if (filepath[0] == '/')
		{
			return (filepath);
		}

		index++;
	}
	filepath = "\0";
	return (NULL);
}
