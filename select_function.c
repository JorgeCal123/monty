#include "monty.h"

stack_t *data = NULL;

/**
 * read_file - read the file
 * @ruta: is the route to open the file
 */

void read_file(char *ruta)
{
	FILE *file_open = NULL;
	char line[100];
	int number_line = 1;

	file_open = fopen(ruta, "r");
	while (fgets(line, 100, file_open) != NULL)
	{
		split_args(line, number_line);
		number_line += 1;
	}
}

/**
 * split_args - separate the arguments of each line
 * @args: is the line to separete
 * @number_line: number of the line
 */
void split_args(char *args, int number_line)
{
	char *slip;
	char *line = (args);
	args_t *head = NULL;
	(void)number_line;

	while ((slip = strtok(line, " \n\t\a\b")))
	{
		add(&head, slip);
		line = NULL;
	}
	select_function(head, number_line);

}

/**
 * select_function - choose the function to execute
 * @head: is the line to separete
 * @number_line: number of the line
 */
void select_function(args_t *head, int number_line)
{
	void (*code_func)(stack_t **, unsigned int);
	(void)number_line;

	while (head != NULL)
	{

		if (strcmp(head->arg, "push") == 0)
		{
			code_func = get_op_func("push");
			code_func(&data, atoi((head->next)->arg));
		}

		/*printf("etsss %d   %s \n", strcmp(head->arg, "pall"), head->arg);*/
		if (strcmp(head->arg, "pall") == 0)
		{
			code_func = get_op_func("pall");
			code_func(&data, 10);
		}
		head = head->next;

	}
	/*printf("\n");*/

}


/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */

void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}
