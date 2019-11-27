#include "bigshell.h"
/**
 * lookpath - looks for the path of the program
 * @command: command entered (echo, pwd, ls, etc)
 * Return: the full path of the program (/bin, /bin/echo, /bin/ls etc)
 *         NULL if fails
 */
char *lookpath(char *command)
{
	char *str = "PATH", *directory, *path_result, **pathtokens;
	int index;

	index = lookenvpath(str);
	pathtokens = divpath(index, str);
	if (pathtokens == NULL)
		return (NULL);
	directory = lookdir(pathtokens, command);
	if (directory == NULL)
	{
		freeptr(pathtokens);
		return (NULL);
	}
	path_result = strpath(directory, command);
	if (path_result == NULL)
	{
		freeptr(pathtokens);
		return (NULL);
	}
	freeptr(pathtokens);
	return (path_result);
}
/**
 * lookenvpath - Look for environmental variable
 * @str: string with the environmental variable
 * Return: index for the variable, if fails -1
 */
int lookenvpath(char *str)
{
	int i, j, len;

	len = _strlen(str);
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (environ[i][j] != str[j])
				break;
		}
		if (j == len && environ[i][j] == '=')
			return (i);
	}
	return (-1);
}

/**
 * divpath - split the path string as array of path directories
 * @index: index of the path in environment variables
 * @str: string to split
 *
 * Return: pointer to strings, NULL if fails
 */
char **divpath(int index, char *str)
{
	char *en_var, **pathtokens;
	int count_token, len;
	const char *delim = ":\n";

	len = _strlen(str);
	count_token = 0;

	en_var = environ[index] + (len + 1);
	pathtokens = maintoken(en_var, delim, count_token);
	if (pathtokens == NULL)
		return (NULL);
	return (pathtokens);
}

/**
 * lookdir - check in directories of pathtokens for the command
 * @pathtokens: pointer to array of paths strings in PATH environmental var
 * @command: command (echo, pwd, /bin/ls, etc)
 * Return: string with the uppermost directory where the command is located
 *         NULL if fails
 */
char *lookdir(char **pathtokens, char *command)
{
	int i, s;
	char *cwd, *buf;
	size_t size = 0;
	struct stat stat_buf;

	buf = NULL;
	cwd = getcwd(buf, size);
	if (cwd == NULL)
		return (NULL);
	if (command[0] == '/')
		command = command + 1;
	for (i = 0; pathtokens[i] != NULL; i++)
	{
		s = chdir(pathtokens[i]);
		if (s == -1)
		{
			perror("ERROR!");
			return (NULL);
		}
		s = stat(command, &stat_buf);
		if (s == 0)
		{
			chdir(cwd);
			free(cwd);
			return (pathtokens[i]);
		}
	}
	chdir(cwd);
	free(cwd);
	return (NULL);
}

/**
 * strpath - join path directory string with command string
 * @directory: directory
 * @command: command
 * Return: string with the full path for a command, NULL if fails
 */
char *strpath(char *directory, char *command)
{
	int i, j, dir_len, command_len, len;
	char *bcommand;

	if (directory == NULL || command == NULL)
		return (NULL);
	dir_len = _strlen(directory) + 1;
	command_len = _strlen(command) + 1;
	len = dir_len + command_len;

	bcommand = malloc(sizeof(char) * len);
	if (bcommand == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		for (j = 0; directory[j] != '\0'; j++, i++)
			bcommand[i] = directory[j];
		bcommand[i] = '/';
		i++;
		for (j = 0; command[j] != '\0'; j++, i++)
			bcommand[i] = command[j];
	}
	bcommand[--i] = '\0';
	return (bcommand);
}
