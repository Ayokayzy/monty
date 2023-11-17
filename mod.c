#include "monty.h"

/**
 * op_mod - This computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: the stack
 * @line_number: line number
 */


void op_mod(stack_t **stack, unsigned int line_number)
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

	if (i < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->prev;
	(*stack)->n = (*stack)->n % temp->n;
	if (*stack)
		(*stack)->next = NULL;
	free(temp);
}
