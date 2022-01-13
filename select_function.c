#include "monty.h"

void read_file(char *ruta)
{
	FILE *file_open = NULL;
	char cadena[100];

	file_open = fopen(ruta, "r");
	while (fgets(cadena, 100, file_open) != NULL)
	{
		printf("%s", cadena);
	}
}

void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", _push},
		{"pall", _pall},
	};

	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}
