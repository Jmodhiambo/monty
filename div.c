#include "monty.h"

/**
 * div_op - Divides the second top element by the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number in the bytecode file.
 */
void div_op(stack_t **stack, unsigned int line_number)
{
        int result;

        /* Check if the stack contains at least two elements */
        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        /* Check if the top element is 0 (division by zero) */
        if ((*stack)->n == 0)
        {
                fprintf(stderr, "L%u: division by zero\n", line_number);
                exit(EXIT_FAILURE);
        }

        /* Perform the division */
        result = (*stack)->next->n / (*stack)->n;

        /* Store the result in the second top element */
        (*stack)->next->n = result;

        /* Remove the top element */
        pop_op(stack, line_number);
}
