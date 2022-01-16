#include "monty.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * main - Description
 * @argc: Description
 * @argv: Description
 * Return: Description
 */

int main(int argc, char **argv)
{
	char *ruta;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	ruta = argv[1];
	read_file(ruta);

	return (EXIT_SUCCESS);
}
