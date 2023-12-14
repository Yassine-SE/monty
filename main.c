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
		fprintf(stderr, "Error: Can't open file\n");

	read_file(fd);
	fclose(fd);
}

/**
 * r_file - function
 * @f: param
 *
 * Return: 0 success
 */
void r_file(FILE *f)
{
	int n_line; 
	char *buffer = NULL;
	size_t len = 0;
     int format = 0;

	for (n_line = 1; getline(&buffer, &len, f) != -1; n_line++)
		format = parse_line(buffer, n_line, format);

	free(buffer);
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
