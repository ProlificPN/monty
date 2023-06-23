#include "monty.h"

/**
 * parse_instruction - Parses an instruction from a string
 * @str: The string to parse
 *
 * Return: Instruction_t struct containing the opcode and function
 *         pointer.
 */
instruction_t parse_instruction(char *str)
{
	instruction_t instruction = {NULL, NULL};
	char *opcode = strtok(str, " \t\n");

	if (opcode != NULL && opcode[0] != '#')
	{
		instruction.opcode = opcode;
		instruction.f = get_op_func(opcode);
	}

	return (instruction);
}

/**
 * get_op_func - Gets a function pointer for the specified opcode
 * @opcode: The opcode to look up
 *
 * Return: function pointer for specified opcode, or NULL if
 *         opcode is invalid or not supported.
 */
void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
		{"pint", pint},
		{NULL, NULL}
	};
	int i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
			return (opcodes[i].f);

		i++;
	}

	return (NULL);
}

/**
 * free_stack - Frees all nodes in a stack
 * @stack: A pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
 * add_node - Adds a new node to the top of a stack
 * @stack: A pointer to the top of the stack
 * @n: The integer value to store in the new node
 *
 * Return: A pointer to the new node, or NULL on failure
 */
stack_t *add_node(stack_t **stack, int n)
{
	stack_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Initialize the new node */
	new_node->n = n;
	new_node->prev = NULL;

	/* Add the new node to the top of the stack */
	if (*stack != NULL)
		(*stack)->prev = new_node;

	new_node->next = *stack;
	*stack = new_node;

	return (new_node);
}

/**
 * len - Determines the length of a stack.
 * @stack: A pointer to the top of the stack
 * Return: The length of the stack
 */
unsigned int len(stack_t *stack)
{
	unsigned int count = 0;

	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}

	return (count);
}
