#include "monty.h"

/**
  *pall - Prints all the values on the stack.
  *
  *@stack: A pointer to the stack.
  *@line_number: The line number of the pall instruction
  *
  */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void)line_number;

	/* Check if the stack is empty. */
	if (node == NULL)
		return;

	/* Print all the values on the stack. */
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
