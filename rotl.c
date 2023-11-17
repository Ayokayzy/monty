#include "monty.h"

/**
 * op_rotl - Rotates the stack to the top.
 * @stack: stack head
 * @counter: line_number
 */

void op_rotl(stack_t **stack, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp = *stack, *auxi;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	auxi = (*stack)->next;
	auxi->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp;
	(*stack) = auxi;
}
