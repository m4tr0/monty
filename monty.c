#include "monty.h"

/**
 * execute_instructions - Executes Monty instructions from a file
 * @file: Pointer to the input file
 */
void execute_instructions(FILE *file)
{
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t instruction;
	char line[1024];
	char *opcode;

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		instruction.opcode = opcode;

		if (strcmp(instruction.opcode, "push") == 0)
			instruction.f = push;
		else if (strcmp(instruction.opcode, "pall") == 0)
			instruction.f = pall;
		else if (strcmp(instruction.opcode, "pop") == 0)
			instruction.f = pop;
		else if (strcmp(instruction.opcode, "pint") == 0)
			instruction.f = pint;
		else if (strcmp(instruction.opcode, "swap") == 0)
			instruction.f = swap;
		else if (strcmp(instruction.opcode, "add") == 0)
			instruction.f = add;
		else if (strcmp(instruction.opcode, "nop") == 0)
			instruction.f = nop;
		else if (strcmp(instruction.opcode, "sub") == 0)
			instruction.f = sub;
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, instruction.opcode);
			exit(EXIT_FAILURE);
		}

		instruction.f(&stack, line_number);
	}
	free_stack(stack);
}

/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	execute_instructions(file);

	fclose(file);
	exit(EXIT_SUCCESS);
}
