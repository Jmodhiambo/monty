#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number where the opcode is found.
 *
 * Description: If the stack contains less than two elements, 
 *              an error message is printed and the program exits.
 *              The result is stored in the second top element,
 *              and the top element is removed.
 */
void sub(stack_t **stack, unsigned int line_number)
{
        stack_t *temp;
        int result;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        temp = *stack;
        result = temp->next->n - temp->n;

        temp->next->n = result;

         *stack = temp->next;
        free(temp);

        printf("Result of sub: %d\n", result);
}
