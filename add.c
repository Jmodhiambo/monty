#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number where the opcode is found.
 */
void add(stack_t **stack, unsigned int line_number)
{
        int sum;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        sum = (*stack)->n + (*stack)->next->n; /* Add top two elements */
        pop(stack, line_number); /* Remove the top element */
        (*stack)->n = sum; /* Store the result in the new top element */
}
