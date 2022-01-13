#include "monty.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	char *ruta;
	if (argc > 2)
	{
		printf("error de 2 archivos");
		return (EXIT_FAILURE);
	}
	ruta = argv[1];
	read_file(ruta);

	return(EXIT_SUCCESS);

}
