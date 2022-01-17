#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0, length = 0;

	length = count_stack(*stack);

	if (length < 2)
		handle_error(ERR_MOD_USG, NULL, line_number, NULL);

	a = temp->n;

	if (a == 0)
		handle_error(ERR_DIV_ZRO, NULL, line_number, NULL);

	b = temp->next->n;
	temp->next->n = b % a;
	*stack = temp->next;
	free(temp);
}



/**
  * pchar - Prints the char at the top of the stack,
  * followed by a new line
  * @stack: The head of the stack
  * @line_number: The line on which the error occurred
  */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		handle_error(ERR_PCH_EMP, NULL, line_number, NULL);

	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
		handle_error(ERR_PCH_USG, NULL, line_number, NULL);
}



/**
  * pstr - Prints the string starting at the top of the stack,
  * followed by a new line
  * @stack: The head of the stack
  * @line_number: The line on which the error occurred
  */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void) line_number;

	while (curr != NULL)
	{
		if (curr->n == 0 || curr->n < 0 || curr->n > 127)
			break;

		printf("%c", curr->n);
		curr = curr->next;
	}

	printf("\n");
}
