#include "monty.h"

/**
 * op_pint -  prints the value at the top of the stack,
 * followed by a new line.
 * @stack: the stack
 * @line_number: line number
 */


void op_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
