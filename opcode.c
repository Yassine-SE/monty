#include "monty.h"

/**
 * f_func - function
 * @opcode: param
 * @value: param
 * @format: param
 *
 * Return: 0 success
 */
void f_func(char *opcode, char *value, int ln, int format)
{
	int i, flag;

	instruction_t func_l[] = {
		{"push", push_stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_l[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_l[i].opcode) == 0)
		{
			c_func(func_l[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}

	if (flag == 1)
		err(3, ln, opcode);
}

/**
 * c_func - function
 * @func: param
 * @op: param
 * @val: param
 * @ln: param
 * @format: param
 *
 * Return: 0 success
 */
void c_func(op_f func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag, i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (!val)
			err(5, ln);

		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = c_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_queue(&node, ln);
	}
	else
		func(&head, ln);
}
