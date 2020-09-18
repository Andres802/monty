#include "monty.h"
/**
 * error_handler - Function to handle error on runtime
 * @ID_case: ID case
 * @opcode: operation code
 * @line: line where error ocurred
 * @ID_case: ID case of error
 */
void error_handler(int ID_case, char *opcode, int line)
{
	switch (ID_case)
	{
		case 3:
			dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line, opcode);
			break;
		case 5:
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line);
			break;
		default:
			break;
	}
	free_nodes();
	free(v->linestr);
	fclose(v->fd);
	free(v);
	exit(EXIT_FAILURE);
}
