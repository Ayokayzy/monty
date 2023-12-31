#include "monty.h"

/**
 * execute - executes each line of code in
 * the monty file
 * Return: returns 0 if success or 1 if failure
 */

int execute(void)
{
	int i;
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"nop", op_nop},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{NULL, NULL}
	};

	data.opcode = strtok(data.line, " \n\t");
	data.arg = strtok(NULL, " \n\t");
	if (!data.opcode || data.opcode[0] == '#')
	{
		return (0);
	}

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(instructions[i].opcode, data.opcode) == 0)
		{
			instructions[i].f(&data.stack, data.line_count);
			return (0);
		}
	}
	fprintf(
		stderr, "L%d: unknown instruction %s\n", data.line_count, data.opcode
	);
	return (1);
}
