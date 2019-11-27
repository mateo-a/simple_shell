#include "bigshell.h"
/**
 * checkinfo - Check the information enter by the user and look for commands
 * @strn: string with the user input
 * @size: size of string, always is initialized as 0
 * @count_commands: counter of commandstr_lens entered
 * @av: argument indicating name of the command
 */
void checkinfo(char *strn, size_t size, int count_commands, char **av)
{
	int i, count_token = 0;
	ssize_t str_len;
	char **array_param;
	const char *delim = "\n\t ";

	write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
	str_len = getline(&strn, &size, stdin);
	if (str_len != -1)
	{
		array_param = maintoken(strn, delim, count_token);
		if (array_param[0] == NULL)
		{
			freestr(2, array_param, strn);
			return;
		}
		i = intfunct(array_param, strn);
		if (i == -1)
			new_command(array_param, strn, count_commands, av);
		for (i = 0; array_param[i] != NULL; i++)
			free(array_param[i]);
		freestr(2, array_param, strn);
	}
	else
		free_exit(strn);
}

/**
 * new_command - Create a duplicate process for the new command
 * @array_param: points to string with the name of the program and parameters
 * @strn: string with the user input
 * @count: count commands that were entered
 * @av: arguments vector, name of the program
 */
void new_command(char **array_param, char *strn, int count, char **av)
{
	pid_t id;
	int status, i, check;
	struct stat buf;
	char *command_tmp, *command;

	id = fork();
	if (id == 0)
	{
		command_tmp = array_param[0];
		command = lookpath(array_param[0]);
		if (command == NULL)
		{
/*Find file in current directory*/
			check = stat(command_tmp, &buf);
			if (check == -1)
			{
				wrterror(av[0], count, command_tmp);
				printfun(": not found", 0);
				freestr(2, strn, command_tmp);
				for (i = 1; array_param[i]; i++)
					free(array_param[i]);
				free(array_param);
				exit(100);
			}
/*The file is in cwd or has full path*/
			command = command_tmp;
		}
		array_param[0] = command;
		if (array_param[0] != NULL)
		{
			if (execve(array_param[0], array_param, environ) == -1)
				wrterrex(av[0], count, command_tmp);
		}
	}
	else
		wait(&status);
}

/**
 * maintoken - work with token functions allowing access in different parts
 *             of code
* @strn: string with the user input
* @delim: constant delimeter to divtokens
* @count_token: count tokens
* Return: tokens array for the command, NULL if fail
 */
char **maintoken(char *strn, const char *delim, int count_token)
{
	char **array_param;

	count_token = numtoken(strn, delim);
	if (count_token == -1)
	{
		free(strn);
		return (NULL);
	}
	array_param = divtokens(count_token, strn, delim);
	if (array_param == NULL)
	{
		free(strn);
		return (NULL);
	}
	return (array_param);
}

/**
 * divtokens - split the string in an array of tokens
 * @count_token: count tokens
 * @strn: string with the user input
 * @delim: constant delimeter
 * Return: pointer NULL terminated with the tokens
 */
char **divtokens(int count_token, char *strn, const char *delim)
{
	int i;
	char **buffer, *token, *copystr;

	copystr = _strdup(strn);
	buffer = malloc(sizeof(char *) * (count_token + 1));
	if (buffer == NULL)
		return (NULL);
	token = strtok(copystr, delim);
	for (i = 0; token != NULL; i++)
	{
		buffer[i] = _strdup(token);
		token = strtok(NULL, delim);
	}
	buffer[i] = NULL;
	free(copystr);
	return (buffer);
}

/**
 * numtoken - Counts tokens in the passed string.
 * @strn: string with the user input
 * @delim: constant delimeter
 * Return: number of tokens, -1 if fails
 */
int numtoken(char *strn, const char *delim)
{
	char *str, *token;
	int i;

	str = _strdup(strn);
	if (str == NULL)
		return (-1);
	token = strtok(str, delim);
	for (i = 0; token != NULL; i++)
		token = strtok(NULL, delim);
	free(str);
	return (i);
}
