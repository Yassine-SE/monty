#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*op_f)(stack_t **, unsigned int);
extern stack_t *head;

void o_file(char *f_name);
void r_file(FILE *f);
stack_t *c_node(int n);
int p_line(char *buffer, int line_n, int format);
void add_queue(stack_t **stack, unsigned int n_line);
void free_nodes(void);

void f_func(char *opcode, char *value, int ln, int format);
void c_func(op_f func, char *op, char *val, int ln, int format);

void push_stack(stack_t **stack, unsigned int n_line);
void pall_stack(stack_t **stack, unsigned int n_line);
void pint_stack(stack_t **stack, unsigned int n_line);
void pop_stack(stack_t **stack, unsigned int n_line);

#endif
