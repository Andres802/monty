#include "monty.h"

/**
 * pop_func - Removes the top node
 * @stack: Head of the list
 * @line: number of the line
 * Return: Nothing
 */
void pop_func(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line);
		fclose(v->fd);
		free(v->linestr);
		free(v);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp = *stack;
		if (tmp->next != NULL)
			tmp->next->prev = NULL;
		*stack = (*stack)->next;
		free(tmp);
	}
}
/**
 * push_func - Appends a node on top of list
 * @node: Node to be added
 * @line: number of the line
 * Return: Nothing
 */
void push_func(stack_t **node, unsigned int line)
{
	stack_t *temp;

	(void)line;
	if (node == NULL || *node == NULL)
	{
		free_nodes();
		fclose(v->fd);
		free(v->linestr);
		free(v);
		exit(EXIT_FAILURE);
	}
	if (v->head == NULL)
	{
		v->head = *node;
		return;
	}
	temp = v->head;
	v->head = *node;
	v->head->next = temp;
	temp->prev = v->head;
}
/**
 * pall_func - Print the list
 * @stack: Head of list
 * @line: number of the line
 * Return: Nothing
 */
void pall_func(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	temp = *stack;
	(void)line;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint_func - Print the top element of list
 * @stack: Head of list
 * @line: number of the line
 * Return: Nothing
 */
void pint_func(stack_t **stack, unsigned int line)
{

	(void)line;
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line);
		free_nodes();
		fclose(v->fd);
		free(v->linestr);
		free(v);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * swap_func - swaps the top two elements of the stack.
 * @stack: Head of list
 * @line: number of the line
 * Return: Nothing
 */
void swap_func(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	temp = *stack;
	(void)line;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line);
		free_nodes();
		fclose(v->fd);
		free(v->linestr);
		free(v);
		exit(EXIT_FAILURE);
	}

	if (temp->next->next == NULL)
	{
		*stack = temp->next;
		(*stack)->next = temp;
		(*stack)->prev = NULL;
		temp->next = NULL;
		temp->prev = *stack;
	}
	else
	{
		(*stack) = temp->next;
		temp->next = (*stack)->next;
		(*stack)->next->prev = temp;
		(*stack)->prev = NULL;
		(*stack)->next = temp;
		temp->prev = *stack;
	}
}
