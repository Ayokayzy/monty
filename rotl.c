#include "monty.h"

/**
 * op_rotl - Rotates the stack to the top.
 * @stack: stack head
 * @counter: line_number
 */

void op_rotl(stack_t **stack, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp = *stack, *auxi;

	if (!*stack || !stack)
	{
		return;
	}

	if (temp->prev == NULL || temp->prev->prev == NULL)
	{
		return;
	}
	auxi = (*stack)->prev;
	auxi->next = NULL;
	data.stack = auxi;
	while (auxi->prev != NULL)
	{
		auxi = auxi->prev;
	}
	auxi->prev = temp;
	temp->next = auxi;
	temp->prev = NULL;
}
