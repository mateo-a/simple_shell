#include "bigshell.h"

/**
 * sig_handler - handle the interrupt signal
 * @signo: int
 * Return: void
 */
void sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
	}
}
/**
 * main - Entry point of the program
 * @ac: Count arguments
 * @av: Arguments vector, name of the program
 * @env: Array of pointers to environment variables
 * Return: 0
 */
int main(int ac, char *av[], char *env[])
{
	char *strn;
	size_t size;
	int count_commands = 0;
	(void) ac;
	(void) env;

	if (signal(SIGINT, sig_handler) == SIG_ERR)
		printf("\ncan't catch SIGINT\n");
	do {
		count_commands++;
		strn = NULL;
		size = 0;
		checkinfo(strn, size, count_commands, av);
	} while (1);
	return (0);
}
