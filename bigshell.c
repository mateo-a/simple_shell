#include "bigshell.h"
/**
 * main - Entry point of the program
 * @ac: Count arguments
 * @av: Arguments vector, name of the program
 * @env: Array of pointers to environment variables
 * Return: 0
 */
int main(__attribute__((unused)) int ac, char **av)
{
	char *strn = NULL;
	size_t size = 0;
	int count_commands = 0;

	while (1) {
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
		signal(SIGINT, SIG_IGN);
		count_commands++;
		/*	strn = NULL;
	       	size = 0;*/
		checkinfo(strn, size, count_commands, av);
	}
	return (0);
}
