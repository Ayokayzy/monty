#include "monty.h"

/**
 * main - Entry point
 * @argv: argument vector
 * @argc: argument count
 * description: Monty interpreter
 * Return: always zero(0)
 */

monty_data data = {NULL, 0, NULL, NULL, NULL};

int main(int argc, char **argv)
{
	FILE *file;
	char buff[1024];
	int status;

	if (argc != 2)
	{
		write(1, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		
		write(1, "Error: Can't open file ", 24);
		write(1, argv[1], strlen(argv[1]));
		write(1, "\n", 1);
		exit(EXIT_FAILURE);
	}
	else
	{
		while(fgets(buff, 1024, file))
		{
			data.line = buff;
			data.line_count++;
			status = execute();
			if (status == 1)
			{
				write(1, "L", 2);
				write(1, "num", 4);
				write(1, ": unknown instruction", 22);
				write(1, data.opcode, strlen(data.opcode));
				write(1, "\n", 2);
				exit(EXIT_FAILURE);
			}

		}
	}
	return (0);
}
