#include "monty.h"
/**
 * rotl_func - top element of the stack becomes the last one,
 *  and the second top element of the stack becomes the first one
 * @stack: Head of the list
 * @line: line of file
 * Return: Nothing
 */
void rotl_func(stack_t **stack, unsigned int line)
{

	stack_t *tmp;
	(void)line;

	tmp = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	/* go to last node 🔁 */
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
/**
 * rotr_func - rotates the stack to the bottom.
 * rotates the stack to the bottom.
 * @stack: Head of the list
 * @line: line of file
 * Return: Nothing
 */
void rotr_func(stack_t **stack, unsigned int line)
{

	stack_t *tmp;
	(void)line;

	tmp = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	/* go to last node 🔁 */
	while (tmp->next != NULL)
		tmp = tmp->next;
	/* change the last to top ↘️*/
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
