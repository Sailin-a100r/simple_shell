#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

int controller(char *, char *[]);
int logstr(char *str);
int count(char *str);
char **set_argvec(char *, char *argvec[]);
char *get_envar(char *var);
void *_realloc(void *, unsigned int, unsigned int);

extern char **environ;
#endif
