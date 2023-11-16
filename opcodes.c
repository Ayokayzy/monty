#include "monty.h"

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *top;

	if (!is_int(data.arg) || !data.arg)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number,
			data.opcode);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		exit(EXIT_FAILURE);
	node->n = atoi(data.arg);
	node->next = NULL;

	if (!stack || !*stack)
	{
		node->prev = NULL;
		*stack = node;
	}
	else
	{
		top = *stack;
		top->next = node;
		node->prev = top;

		*stack = node;
	}
}

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: Stack empty %s\n", line_number,
			data.opcode);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
