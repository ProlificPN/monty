#include "monty.h"

/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 *
 * @stack: A pointer to the stack.
 * @line_number: The line number of the instruction calling function.
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack is empty. */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Print the value at the top of the stack. */
	printf("%d\n", (*stack)->n);
}
