#include "monty.h"

void _push(stack_t **list, unsigned int number)
{
	stack_t *Node = malloc(sizeof(stack_t));
	if (Node == NULL)
		exit(EXIT_FAILURE);
	Node->n = number;
	Node->next = *list;
	*list = Node;
}

void _pall(stack_t **list, unsigned int number)
{
	(void) list;
	(void) number;
}