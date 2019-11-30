#include "bigshell.h"

/**
 * changedir - Change CWD to the parameter in cd, no parameter change HOME
 * @strn: string with the user input
 */

void changedir(char *strn)
{
	int index, count_token = 0;
	char **array_param;
	const char *delim = "\n\t ";

	array_param = maintoken(strn, delim, count_token);
	if (array_param[0] == NULL)
	{
		freestr(2, array_param, strn);
		return;
	}
	if (array_param[1] == NULL)
	{
		index = lookenvpath("HOME");
		chdir((environ[index]) + 5);
	}
	else if (_strcmp(array_param[1], "-") == 0)
		printfun(array_param[1], 0);
	else
		chdir(array_param[1]);
	freeptr(array_param);
}

/**
 * varenv - Print environment variables
 * @strn: string with the user input
 */
void varenv(__attribute__((unused))char *strn)
{
	int i, j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
			write(STDOUT_FILENO, &environ[i][j], 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * free_exit - Exit after free allocated resources
 * @strn: string with the user input
 */
void free_exit(char *strn)
{
	free(strn);
	exit(0);
}

/**
 * intfunct_exe - Lookup for function needed to execute
 * @str: string with the user input
 * Return: pointer to the function, NULL in other cases.
 */
void (*intfunct_exe(char *str))(char *str)
{
	int i;

	buil_t buildin[] = {
		{"exit", free_exit},
		{"env", varenv},
		{"cd", changedir},
		{NULL, NULL}
	};

	for (i = 0; buildin[i].bcommand != NULL; i++)
	{
		if (_strcmp(str, buildin[i].bcommand) == 0)
		{
			return (buildin[i].f);
		}
	}
	return (NULL);
}

/**
 * intfunct - Lookup for builtin functions
 * @command: array of arguments in the shell
 * @strn: string with the user input
 * Return: 0 if the function, -1 Otherwise
 */
int intfunct(char **command, char *strn)
{
	void (*build)(char *);

	build = intfunct_exe(command[0]);
	if (build == NULL)
		return (-1);
	if (_strcmp("exit", command[0]) == 0)
		freeptr(command);
	build(strn);
	return (0);
}
