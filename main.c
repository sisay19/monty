#include "monty.h"

char *push_arg = NULL;

/**
 * main - Monty bytecode interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	FILE *file;
	char line[1024];
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode;
	char *arg;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		/* Remove trailing newline */
		line[strcspn(line, "\n")] = '\0';
		opcode = strtok(line, " \t");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		arg = strtok(NULL, " \t");
		push_arg = arg;
		execute_instruction(opcode, arg, &stack, line_number);
	}
	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
