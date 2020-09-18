#include "monty.h"
/**
 * separate_lines - function to separate the lines
 * @buffer: buffer
 * Return: lines into a double pointer
 */
char **separate_lines(char *buffer)
{
	unsigned int pos = 0;
	char **lines = malloc(sizeof(char *) * BUFFERSIZE);
	char *line = NULL;

	if (lines == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		close(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	line = _strtok(buffer, "\n");
	while (line)
	{
		lines[pos] = checkspaces(line);
		pos++;
		line = _strtok(NULL, "\n");
	}
	fd_flags->totalLines = pos;
	lines[pos] = NULL;
	return (lines);
}
/**
 * splitline - function separate the string in new strings
 * @buffer: string
 * Return:  a pointer to strings.
 */
char **splitline(char *buffer)
{
	unsigned int pos = 0;
	char **words = malloc(sizeof(char *) * BUFFERSIZE);
	char *word = NULL, *bufferline = NULL;

	if (words == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		close(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	bufferline = _strdup(buffer);
	free(buffer);
	word = _strtok(bufferline, " ");
	while (word)
	{
		words[pos] = word;
		pos++;
		word = _strtok(NULL, " ");
	}
	words[pos] = NULL;
	free(word);
	free(bufferline);
	return (words);
}
/**
 * checkspaces - function to check a string of spaces
 * @line: Pointer to string.
 * Return: null or a string without spaces.
 */
char *checkspaces(char *line)
{
	int i = 0;
	char *new;

	while (line[i] != '\0')
	{
		if (line[i] != ' ')
		{
			new = line + i;
			return (new);
		}
		i++;
	}
	return (NULL);
}
