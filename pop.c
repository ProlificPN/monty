#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 *
 * @stack: A pointer to the stack.
 * @line_number: The line number of the instruction.
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	/* Check if the stack is empty. */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Pop the top element of the stack. */
	top = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	/* Free the memory used by the popped element. */
	free(top);
}
