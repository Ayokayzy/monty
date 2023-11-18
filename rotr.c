#include "monty.h"

/**
 * op_rotr - Rotates the stack to the bottom.
 * @stack: stack head
 * @line_number: line_number in the monty file
 */
void op_rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *copy, *last;

	copy = *stack;
	if (!*stack || !stack || !(*stack)->prev)
	{
		return;
	}
	while (copy->prev)
	{
		copy = copy->prev;
	}
	last = copy->next;
	last->prev = NULL;
	(*stack)->next = copy;
	copy->next = NULL;
	copy->prev = *stack;
	data.stack = copy;
}
