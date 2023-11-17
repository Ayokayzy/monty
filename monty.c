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
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (fgets(buff, 1024, file))
		{
			data.line = buff;
			data.line_count++;
			status = execute();
			if (status == 1)
			{
				exit(EXIT_FAILURE);
			}

		}
	}
	free_stack(&data.stack);
	fclose(file);
	return (0);
}
