#ifndef MONTY_H
#define MONTY_H
/* Libraries 📂 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct _globales - struct for global variables
 * @linestr: string of the getline
 * @fd: file descriptor
 * @head: the head of the stack
 */
typedef struct _globales
{
	char *linestr;
	FILE *fd;
	stack_t *head;
} var;

var *v;
void _open(char *file);
void _readfile(void);
void _read_lines(int line);
void call_func(char *op, char *val);
void find_fn(char *opcode, char *val, int line);
stack_t *create_node(int n);
void pop_func(stack_t **node, unsigned int line_number);
void push_func(stack_t **node, unsigned int line_number);
void pall_func(stack_t **node, unsigned int line_number);
void pint_func(stack_t **node, unsigned int line_number);
void swap_func(stack_t **node, unsigned int line);
void add_func(stack_t **node, unsigned int line);
void nop_func(stack_t **node, unsigned int line);
void sub_func(stack_t **stack, unsigned int line);
void mul_func(stack_t **stack, unsigned int line);
void div_func(stack_t **stack, unsigned int line);
void mod_func(stack_t **stack, unsigned int line);
void pchar_func(stack_t **stack, unsigned int line);
void pstr_func(stack_t **stack, unsigned int line);
void rotl_func(stack_t **stack, unsigned int line);
void rotr_func(stack_t **stack, unsigned int line);
void free_nodes(void);
void error_handler(int ID_case, char *opcode, int line);
#endif /* LISTS_H */
