#include "monty.h"


/**
 * add - add a new argument
 * @head: is the first argument
 * @arg: argument type String
 * Return: structure type args_t
 */

args_t *add(args_t **head, char *arg)
{
	args_t *node,  *aux;

	aux = *head;

	if (arg == NULL)
		return (NULL);

	node = malloc(sizeof(args_t));
	if (node == NULL)
		return (NULL);

	node->arg = arg;
	node->next = NULL;

	if (*head == NULL)
	{
	*head = node;
	return (node);
	}

	while (aux->next)
		aux = aux->next;

	aux->next = node;

	return (aux);
}

/**
 * print_list - print all list args_t
 * @h: list type argms_t
 * Return: size of list
 */

size_t print_list(const args_t *h)
{
	size_t elements = 0;

	while (h != NULL)
	{
		printf("%s\n", h->arg);
		h = h->next;
		elements++;
	}
	return (elements);
}
