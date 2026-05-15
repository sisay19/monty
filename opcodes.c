#include "monty.h"

/**
 * push - pushes an integer onto the stack
 * @stack: double pointer to the top of the stack
 * @line_number: current line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node;

	if (push_arg == NULL || is_integer(push_arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(push_arg);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all values on the stack from top to bottom
 * @stack: double pointer to the top of the stack
 * @line_number: line number (unused)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
