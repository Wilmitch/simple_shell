#include "my_shell.h"

/**
 * tokenizer - This tokenizes input and stores it into an array.
 * @input_string: parsed input.
 * @delim: delimiter to be used, needs to be one character string.
 *
 * Return: array of tokens
 */

char **tokenizer(char *input_string, char *delim)
{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;

	token = _strtok_r(input_string, delim, &save_ptr);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = _strtok_r(NULL, delim, &save_ptr);
		num_delim++;
	}

	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;

	return (av);
}

/**
 * print - This will print a string to stdout.
 * @string: string to be printed.
 * @stream: stream to print out to the stdout.
 *
 * Return: void, return nothing
 */

void print(char *string, int stream)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
		write(stream, &string[i], 1);
}

/**
 * remove_newline - This will remove the new line from a string.
 * @str: string to be used
 *
 * Return: void
 */

void remove_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}

/**
 * _strcpy - This will copy a string to another buffer.
 * @source: source to copy the string from.
 * @dest: destination to copy the string to.
 *
 * Return: void
 */

void _strcpy(char *source, char *dest)
{
	int i = 0;

	for (; source[i] != '\0'; i++)
		dest[i] = source[i];
	dest[i] = '\0';
}

/**
 * _strlen - This counts length of the string.
 * @string: string whose length is to be counted.
 *
 * Return: length of the string.
 */

int _strlen(char *string)
{
	int len = 0;

	if (string == NULL)
		return (len);
	for (; string[len] != '\0'; len++)
		;
	return (len);
}
