#include "monty.h"

/**
 * o_file - function
 * @f_name: param
 *
 * Return: 0 success
 */
void o_file(char *f_name)
{
	FILE *fd;

     fd = fopen(f_name, "r");
	if (!f_name || !fd)
		fprintf(stderr, "Error: Can't open file\n");

	r_file(fd);
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
	ssize_t nline = 0;
     int format = 0;

     nline = getline(&buffer, &len, f);
	for (n_line = 1; nline != -1; n_line++)
		format = p_line(buffer, n_line, format);

	free(buffer);
}
