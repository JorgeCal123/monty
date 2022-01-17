#include "monty.h"

/**
 * push - add a new element to the stack
 * @stack: is the list o stack type stack_t
 * @param: argument to add the list type int
 */
void push(stack_t **stack, unsigned int param)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		handle_error(ERR_BAD_MALL, NULL, 0, NULL);

	new_node->n = param;
	if (*stack)
	{
		new_node->next = *stack;
		new_node->prev = (*stack)->prev;
		(*stack)->prev = new_node;
		*stack = new_node;
		return;
	}

	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

/**
 * pall - print the element of the stack
 * @stack: is the list o stack type stack_t
 * @line_number: argument to add the list type int
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	(void) line_number;

	if (*stack)
	{
		current = *stack;
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}


/**
 * pint - Prints the value at the top of the stack,
 * followed by a new line.
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		handle_error(ERR_PINT_USG, NULL, line_number, NULL);

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *temp = NULL;

	if (*stack == NULL)
		handle_error(ERR_POP_USG, NULL, line_number, NULL);

	temp = current;
	if (current->next)
	{
		current = current->next;
		current->prev = temp->prev;
		*stack = current;
	}
	else
	{
		*stack = NULL;
	}

	free(temp);
}



/**
 * swap - Swaps the top two elements of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	unsigned int length = 0, temp = 0;

	length = count_stack(*stack);

	if (length < 2)
		handle_error(ERR_SWAP_USG, NULL, line_number, NULL);

	if (*stack)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
}



