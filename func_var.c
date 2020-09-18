#include "monty.h"
/**
 *open_file - fopen function
 *@av: the array of command line argument strings
 *
 *Return: 0 always
 */
FILE *open_file(char **av)
{
	FILE *file;

	file = fopen(av[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	return (file);
}
