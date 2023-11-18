#include "monty.h"

/**
 * op_rotl - Rotates the stack to the top.
 * @stack: stack head
 * @counter: line_number
 */

void op_rotl(stack_t **stack, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp = *stack, *auxi, *zero_data;

	if (!*stack || !stack)
	{
		return;
	}

	if (temp->prev == NULL)
	{
		zero_data = malloc(sizeof(stack_t));
		temp->next = zero_data;
		zero_data->prev = temp;
		zero_data->next = NULL;
		zero_data->n = 0;
		*stack = zero_data;
		temp = *stack;
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
