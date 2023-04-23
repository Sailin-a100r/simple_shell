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
 *
 * Return: array of strings of directories of $PATH
 */
char **get_dirarray(char *path)
{
	char *dirname, **dirarray;
	int dircount, index;

	/* count number of directories in the path */
	dircount = countchar(path, ':') + 1;
	dirarray = malloc(dircount * sizeof(char *));
	if (!dirarray)
		return (NULL);

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
 * Return: pointer to a copied string of $PATH
 */
char *get_path(void)
{
	char *pathpt, *path;
	int pathlen;

	/* pointer to the path environment variable */
	pathpt = get_envar("PATH");
	/* count the number of chars in the path */
	pathlen = count(pathpt);
	/* copy the path as string */
	path = malloc(pathlen * sizeof(char));

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
 *
 * Return: On success returns full path to the file
 * On failure returns NULL
 */
char *search_dir(char *dirname, char *filename)
{
	DIR *dir; /* pointer to open directory */
	struct dirent *entity; /* pointer to the structure returned */
	char *fullpath;

	fullpath = malloc(256 * sizeof(char));
	dir = opendir(dirname);
	if (dir == NULL)
		return (NULL);

	entity = readdir(dir);
	while (entity)
	{
		if (_strcmp(entity->d_name, filename) == 0)
		{ /* success */
			_strcpy(fullpath, dirname);
			_strcat(fullpath, "//");
			_strcat(fullpath, filename);
			closedir(dir);
			return (fullpath);
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
 *
 * Return: Onsuccess return the full path of the program,
 * Onfailure return NULL
 */

char *search_path(char **dirarray, char *filename)
{
	int index = 0;
	char *fullpath;

	while (dirarray[index])
	{
		fullpath = search_dir(dirarray[index], filename);
		if (fullpath)
		{
			return (fullpath);
		}
		index++;
	}
	return (NULL);
}
