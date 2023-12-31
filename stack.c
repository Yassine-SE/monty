#include "monty.h"

/**
 * push_stack - function
 * @stack: param
 * @n_line: param
 */
void push_stack(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp;
	(void) n_line;

	if (!stack || !*stack)
		exit(EXIT_FAILURE);
	if (!head)
	{
		head = *stack;
		return;
	}
	tmp = head;
	head = *stack;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * pall_stack - function
 * @stack: param
 * @n_line: param
 */
void pall_stack(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp;
	(void) n_line;

	if (!stack)
		exit(EXIT_FAILURE);

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint_stack - function
 * @stack: param
 * @n_line: param
 */
void pint_stack(stack_t **stack, unsigned int n_line)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", n_line);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop_stack - function
 * @stack: param
 * @n_line: param
 */
void pop_stack(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", n_line);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;
	if (*stack)
		(*stack)->prev = NULL;

	free(tmp);
}
