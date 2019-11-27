#include "bigshell.h"
/**
 * freestr - free pointers to a string
 * @n: number of pointers to be freed
 */
void freestr(int n, ...)
{
	int i;
	char *str;
	va_list a_list;

	va_start(a_list, n);
	for (i = 0; i < n; i++)
	{
		str = va_arg(a_list, char*);
		if (str == NULL)
			str = "(nil)";
		free(str);
	}
	va_end(a_list);
}

/**
 * freeptr - free double pointer variables
 * @to_be_freed: address to be freed
 */
void freeptr(char **to_be_freed)
{
	int index;

	for (index = 0; to_be_freed[index] != NULL; index++)
		free(to_be_freed[index]);
	free(to_be_freed);
}

/**
 * wrterrex - write exec errors
 * @av: argument vector with the name of the program running
 * @count: counter of the number of commands run on the shell
 * @command_tmp: command
 */

void wrterrex(char *av, int count, char *command_tmp)
{
	wrterror(av, count, command_tmp);
	printfun(": ", 1);
	perror("");
	exit(1);
}

/**
 * wrterror - write message error when command is not found
 * @count: counter of the number of commands run on the shell
 * @av: argument vector with the name of the program running
 * @command: command
 */
void wrterror(char *av, int count, char *command)
{
	printfun(av, 1);
	printfun(": ", 1);
	wrtnum(count);
	printfun(": ", 1);
	printfun(command, 1);
}

/**
 * _strlen - function that return the lenght of a string
 * @str: string
 * Return: length, otherwise 0.
 */
int _strlen(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
