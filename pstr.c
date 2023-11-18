#include "monty.h"

/**
 * op_pstr - This prints the string starting at the top of the stack
 * followed by a new line.
 * @stack: Stack head
 * @line_number: line_number in the monty file
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *stack;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->prev;
	}
	printf("\n");
}
