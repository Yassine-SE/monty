#include "monty.h"

stack_t *head = NULL;

/**
 * main - main
 * @argc: param
 * @argv: param
 *
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	o_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * c_node - function
 * @n: param
 *
 * Return: 0 success
 */
stack_t *c_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * p_line - function
 * @buffer: param
 * @line_n: param
 * @format: param
 *
 * Return: 0 success
 */
int p_line(char *buffer, int line_n, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (!buffer)
		err(4);

	opcode = strtok(buffer, delim);
	if (!opcode)
		return (format);

     value = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	f_func(opcode, value, line_n, format);
	return (format);
}

/**
 * add_queue - function
 * @stack: param
 * @n_line: param
 *
 * Return: 0 success
 */
void add_queue(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp;
	(int) *n_line;

	if (!stack || !*stack)
		exit(EXIT_FAILURE);
	if (!head)
	{
		head = *stack;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
}

/**
 * free_nodes - function
 *
 * Return: 0 success
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (!head)
		return;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
