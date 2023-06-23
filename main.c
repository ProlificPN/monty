#include "monty.h"


/**
 * main - Entry point for the Monty program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: EXIT_SUCCESS if the program executes successfully,
 *         or EXIT_FAILURE if an error occurs.
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char line[MAX_LINE_LENGTH];
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	instruction_t instruction;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* Open the specified file for reading */
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	while (fgets(line, MAX_LINE_LENGTH, fp) != NULL)
	{
		line_number++;
		if (line[strlen(line) -1] == '\n')
			line[strlen(line) -1] = '\0';
		/* Parse the instruction from the current line */
		instruction = parse_instruction(line);
		/* Execute the instruction */
		if (instruction.opcode != NULL && instruction.f != NULL)
			instruction.f(&stack, line_number);
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s", line_number, line);
			exit(EXIT_FAILURE);
		}
	}
	/* Clean up resources and exit */
	fclose(fp);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
