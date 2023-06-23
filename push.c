#include "monty.h"

/**
 * push - function to push an interger onto the stack
 * @stack: Pointer to the stack
 * @line_number: Integer to be added onto the stack
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
        char *arg;
        int n;

        /* Get the argument for the push instruction */
        arg = strtok(NULL, " \t\n");
        if (arg == NULL)
        {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }

        /* Convert the argument to an integer */
        n = atoi(arg);
        if (n == 0 && arg[0] != '0')
        {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }

        /* Push the integer onto the stack */
        add_node(stack, n);
}
