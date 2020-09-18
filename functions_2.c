#include "monty.h"

/**
 * add_func - adds the top two elements of the stack.
 * @stack: Head of the list
 * @line: line of file
 * Return: Nothing
 */
void add_func(stack_t **stack, unsigned int line)
{
	int result;
	(void)line;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line);
		free_nodes();
		fclose(v->fd);
		free(v->linestr);
		free(v);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	result = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * nop_func - Do nothing
 * @stack: Head of the list
 * @line_number: line of file
 * Return: Nothing
 */
void nop_func(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * sub_func - adds the top two elements of the stack.
 * @stack: Head of the list
 * @line: line of file
 * Return: Nothing
 */
void sub_func(stack_t **stack, unsigned int line)
{
	int result;
	(void)line;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line);
		free_nodes();
		fclose(v->fd);
		free(v->linestr);
		free(v);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	result = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * mul_func - divs the top two elements of the stack.
 * @stack: Head of the list
 * @line: line of file
 * Return: Nothing
 */
void mul_func(stack_t **stack, unsigned int line)
{
	int result;
	(void)line;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line);
		free_nodes();
		fclose(v->fd);
		free(v->linestr);
		free(v);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	result = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
