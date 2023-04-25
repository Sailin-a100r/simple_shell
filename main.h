#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

int controller(char *, char *[], char **, size_t *);
int logstr(char *str);
int count(char *str);
char **set_argvec(char *, char *argvec[]);
char *get_envar(char *var);
void *_realloc(void *, unsigned int, unsigned int);
int countchar(char *, char);
char *get_path(char *path);
char **get_dirarray(char *path, char **dirarray);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *search_dir(char *dirname, char *filename, char *filepath);
int _strcmp(char *s1, char *s2);
char *search_path(char **dirarray, char *filename, char *filepath);
void pathnotfound(void);
char **free_array(char **array);
int start_process(char **argvec, char **envp);

extern char **environ;

/**
 * dirent_t - typedef for struct dirent
 */
/*typedef struct dirent dirent_t;*/
#endif
