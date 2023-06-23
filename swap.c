#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 *
 * @stack: A pointer to the stack.
 * @line_number: The line number of the instruction.
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second_top;
	int temp;

	/* Check if the stack contains less than two elements. */
	if (len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Swap the top two elements of the stack. */
	top = *stack;
	second_top = (*stack)->next;

	/* Swap the values of the two elements. */
	temp = top->n;

	top->n = second_top->n;
	second_top->n = temp;
}
