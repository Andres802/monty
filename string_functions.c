#include "monty.h"
/**
 * _strtok - function separate the string in tokens
 * @arg: string
 * @dlm: delimiter
 * Return: a pointer to the next token
 */
char *_strtok(char *arg, char *dlm)
{
	static char *token;
	int c = 0, found = 0, i = 0;
	char *str = NULL;

	if (!dlm || (arg == NULL && token == NULL))
		return (0);
	if (arg != NULL)
		str = arg;
	if (arg == NULL)
		str = token;
	while (str[i] == dlm[0])
		i++;
	for (c = i; str[c] != '\0'; c++)
		if (str[c] == dlm[0])
		{
			found = 1;
			break;
		}
	for ( ; str[c] != '\0'; c++)
		if (str[c] != dlm[0])
			break;
		else if (str[c + 1] == '\0')
		{
			str[c] = '\0';
			found = 0;
			break;
		}
		else
			str[c] = '\0';
	if (!found)
	{
		token = NULL;
		return (str + i);
	}
	if (*(str + c) != '\0')
		token = str + c;
	else
		token = '\0';
	return (str + i);
}
/**
 * _strdup - function to copy an array with new memory address
 * @str: array to be copy
 * Return: the new array
 */
char *_strdup(char *str)
{
	char *p;
	unsigned int a = 0, len;

	if (str == NULL)
		return (NULL);
	len = strlen(str);
	p = malloc(len + 1 * sizeof(char));
	if (p == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		close(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	for ( ; a < len; a++)
		p[a] = str[a];
	p[a] = str[a];
	return (p);
}
