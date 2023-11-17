#include "monty.h"

/**
 * op_pop - removes the top element of the stack.
 * followed by a new line.
 * @stack: the stack
 * @line_number: line number
 */


void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->prev;
	if (*stack)
		(*stack)->next = NULL;
	free(temp);
}
