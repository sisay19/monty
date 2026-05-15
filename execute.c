#include "monty.h"

/**
 * execute_instruction - dispatches opcode to the correct function
 * @opcode: operation code
 * @arg: argument (may be NULL)
 * @stack: double pointer to the stack
 * @line_number: current line number
 */
void execute_instruction(char *opcode, char *arg, stack_t **stack,
		unsigned int line_number)
{
	(void)arg;

	if (strcmp(opcode, "push") == 0)
		push(stack, line_number);
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
                pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
