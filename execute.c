#include "monty.h"

/**
 * execute - executes each line of code in
 * the monty file
 * Return: returns 0 if success or 1 if failure
 */

int execute()
{
	int i;
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL}
	};

	data.opcode = strtok(data.line, " \n\t");
	data.arg = strtok(NULL, " \n\t");
	if (!data.opcode || data.opcode[0] == '#') {
		return (1);
	}

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(instructions[i].opcode, data.opcode) == 0)
		{
			instructions[i].f(&data.stack, data.line_count);
			return (0);
		}
	}
	return (1);
}
