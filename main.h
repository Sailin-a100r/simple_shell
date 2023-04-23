#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

int controller(char *, char *[], char **);
int logstr(char *str);
int count(char *str);
char **set_argvec(char *, char *argvec[]);
char *get_envar(char *var);
void *_realloc(void *, unsigned int, unsigned int);
int countchar(char *, char);
char *get_path(void);
char **get_dirarray(char *);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *search_dir(char *dirname, char *filename);
int _strcmp(char *s1, char *s2);
char *search_path(char **dirarray, char *filename);
void pathnotfound(void);

extern char **environ;

/**
 * struct dirent - directory entity
 * @d_ino: Inode number
 * @d_off: Not an offset
 * @d_reclen: Length of this record
 * @d_type: Type of file
 * @d_name: Null-terminated filename
 */
/*typedef struct dirent
{
	ino_t d_ino;
	off_t d_off;
	unsigned short d_reclen;
	unsigned short d_type;
	char d_name[256];
} dirent_t;
*/
#endif
