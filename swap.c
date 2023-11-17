#include "monty.h"

/**
 * op_swap - swaps the top two elements of the stack.
 * @stack: the stack
 * @line_number: line number
 */


void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int i = 0, num;

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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->prev;
	num = (*stack)->n;

	(*stack)->n = temp->n;
	temp->n = num;
}
