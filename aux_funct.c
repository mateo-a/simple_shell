#include "bigshell.h"

/**
 * wrtnum - write a number
 * @n: unsigned integer
 * Return: numbers to be printed
 */
int wrtnum(int n)
{
	int div = 1, len = 0;
	unsigned int num = n;

	for (; num / div > 9; )
		div *= 10;
	for (; div != 0; )
	{
		len += _put_char('0' + num / div);
		num %= div;
		div /= 10;
	}
	return (len);
}

/**
 * _strdup - copy a string
 * @src: source string
 * Return: dest string
 */
char *_strdup(char *src)
{
	int i, len;
	char *dest;

	len = _strlen(src);
	dest = malloc(sizeof(char) * (len + 1));

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * printfun - print string by character
 * @str: string, if is NULL prints (null)
 * @new_line: just if is 0 a new line is printed
 */
void printfun(char *str, int new_line)
{
	int i;

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		write(STDOUT_FILENO, &str[i], 1);
	if (new_line == 0)
		write(STDOUT_FILENO, "\n", 1);
}

/**
 * _put_char - writes a character to stdout
 * @c: character to be printed
 * Return: On  success,  the  number  of bytes written.
 */
int _put_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcmp - compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if strings match, -1 if fails.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	if (_strlen(s1) != _strlen(s2))
		return (-1);
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}
