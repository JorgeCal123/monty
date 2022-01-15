#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>



extern int number;

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



typedef struct args_s
{
	char* arg;
        struct args_s *next;
} args_t;


/*	select_function.c	*/
void read_file(char *ruta);
void split_args(char *args, int number_line);
void select_function(args_t *head, int number_line);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);


/*        function_1.c           */
void _push(stack_t **list, unsigned int number);
void _pall(stack_t **list, unsigned int number);

/*	    list.c		 */
args_t *add(args_t **head, char *arg);
size_t print_list(const args_t *h);


#endif
