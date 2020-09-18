#include "monty.h"


/**
 * _open - Function to open the file and check file is accesible
 * @file: file to be open
 * Return: Nothing
 */
void _open(char *file)
{
		v->fd = fopen(file, "r");
		if (v->fd == NULL)
		{
			dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
			free_nodes();
			free(v);
			exit(EXIT_FAILURE);
		}
		/** Go to read the file 📄*/
		_readfile();
		/* Close the file ❌*/
		fclose(v->fd);
}
/**
 * _readfile - function to read the lines of the opened file
 * Return: Nothing
 */
void _readfile(void)
{
	/** read all the file */
	int line;
	size_t n;
	/* Go trough each line ⤵️ */
	for (line = 1; getline(&v->linestr, &n, v->fd) != EOF; line++)
		_read_lines(line);
	/** Free the line */
	free(v->linestr);
}
/**
 * _read_lines - Function to separate the line into tokens
 * @line: number of the line to read
 * Return: Nothing
 */
void _read_lines(int line)
{
	char *opcode = NULL;
	char *value = NULL;


	if (v->linestr == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_nodes();
		fclose(v->fd);
		free(v->linestr);
		free(v);
		exit(EXIT_FAILURE);
	}
	opcode = strtok(v->linestr, " \r\t\n");
	if (opcode == NULL)
		return;
	value = strtok(NULL, " \r\t\n");
	find_fn(opcode, value, line);
}
/**
 * find_fn - Function to choose the right function
 * depends of the opcode
 * @opcode: Opcode extracted from file
 * @val: value to insert
 * @line: number of the line to read
 * Return: Nothing
 */
void find_fn(char *opcode, char *val, int line)
{
	stack_t *node;	   /** variable to store the node ⏺ */
	int i, j, neg = 1; /** counter v 🔀 */
	instruction_t list[] = {
		{"pop", pop_func}, {"push", push_func}, {"pall", pall_func},
		{"pint", pint_func}, {"swap", swap_func}, {"add", add_func},
		{"nop", nop_func}, {"sub", sub_func}, {"mul", mul_func},
		{"div", div_func}, {"mod", mod_func}, {"pchar", pchar_func},
		{"pstr", pstr_func}, {"rotl", rotl_func}, {"rotr", rotr_func},
		{ NULL, NULL }
	};
if (opcode[0] == '#')
	return;
for (i = 0; list[i].opcode != NULL; i++)
{											 /** go through the list to find the function 🔁*/
	if (strcmp(opcode, list[i].opcode) == 0) /* Check if the opcode exist ✅ */
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (val != NULL && val[0] == '-')
				val = val + 1, neg = -1;
			if (val == NULL)
				error_handler(5, opcode, line); /* case 5 error */
			for (j = 0; val[j] != '\0'; j++)
			{
				if (isdigit(val[j]) == 0) /* case 5 error */
					error_handler(5, opcode, line);
			}
			node = create_node(atoi(val) * neg); /* Create node */
			node = node, list[i].f(&node, line);
			break;
		}
		else
		{
			list[i].f(&v->head, line);
			break;
		}
	}
	}
	if (list[i].opcode == NULL)
		error_handler(3, opcode, line); /* Unknow instruction Error*/
}
