#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 *
 * @stack: A pointer to the stack.
 * @line_number: The line number of the instruction
 *
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second_top;

	/* Check if the stack contains less than two elements. */
	if (len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Get the top two elements of the stack. */
	top = *stack;
	second_top = (*stack)->next;

	/* Add the two elements and store the result in the second top element. */
	second_top->n += top->n;

	/* Remove the top element from the stack. */
	free(top);
}
