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
 * o_file - function
 * @f_name: param
 *
 * Return: 0 success
 */
void o_file(char *f_name)
{
	FILE *fd = fopen(f_name, "r");

	if (!f_name || !fd)
		err(2, f_name);

	read_file(fd);
	fclose(fd);
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
