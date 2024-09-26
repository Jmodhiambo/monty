#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the opcode.
 */
void push(stack_t **stack, unsigned int line_number)
{
        char *arg = strtok(NULL, " \n\t");
        int value;

        if (arg == NULL || !is_integer(arg))
        {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }

        value = atoi(arg);
        add_node(stack, value);
}

/**
 * pall - Prints all values on the stack from the top.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the opcode (unused).
 */
void pall(stack_t **stack, unsigned int line_number)
{
        stack_t *current = *stack;

        (void)line_number; /* Unused parameter */

        while (current != NULL)
        {
                printf("%d\n", current->n);
                current = current->next;
        }
}

