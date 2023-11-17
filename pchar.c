#include "monty.h"

/**
 * op_pchar - This prints the char at the top of the stack,
 * followed by a new line.
 * @stack: stack head.
 * @line_number: line_number in the monty file
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	FILE *file = NULL;

	h = *stack;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
