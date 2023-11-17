#include "monty.h"

/**
 * op_sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: the stack
 * @line_number: line number
 */


void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int i = 0;

	if (temp)
	{
		while (temp)
		{
			i++;
			temp = temp->prev;
		}
	}

	temp = *stack;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->prev;
	(*stack)->n = (*stack)->n - temp->n;
	if (*stack)
		(*stack)->next = NULL;
	free(temp);
}
