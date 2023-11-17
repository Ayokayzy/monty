#include "monty.h"

/**
 * free_stack - frees the memory created by the stack
 * @stack: the stack
 */

void free_stack(stack_t **stack)
{
	stack_t *current, *temp;

	current = *stack;

	if (!*stack || !stack)
		return;

	while (current != NULL)
	{
		temp = current;
		current = current->prev;
		free(temp);
	}
}
