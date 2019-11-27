#ifndef BIGSHELL_H
#define BIGSHELL_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <signal.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#define PROMPT "BIGSHELL $ "
/**
 * struct buil_s - Struct to the built-in functions
 * @bcommand: built-in command
 * @f: pointer to function
 */
typedef struct buil_s
{
	char *bcommand;
	void (*f)(char *);
} buil_t;
extern char **environ;
/*checkstr.c*/
void checkinfo(char *, size_t, int, char **);
void new_command(char **, char *, int, char **);
char **maintoken(char *, const char *, int);
char **divtokens(int, char *, const char *);
int numtoken(char *, const char *);
/*directory.c*/
char *lookpath(char *);
int lookenvpath(char *);
char **divpath(int, char *);
char *lookdir(char **, char *);
char *strpath(char *, char *);
/*inc_funct.c*/
int intfunct(char **, char *);
void (*intfunct_exe(char *))(char *);
void free_exit(char *);
void varenv(char *);
void changedir(char *);
/*aux_funct.c*/
int wrtnum(int);
char *_strdup(char *);
void printfun(char *, int);
int _put_char(char);
int _strcmp(char *, char *);
/*aux_funct1.c*/
void freestr(int, ...);
void freeptr(char **);
void wrterrex(char *, int, char *);
void wrterror(char *, int, char *);
int _strlen(char *);
#endif
