#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number where the opcode appears
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
        stack_t *first, *second;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        first = *stack;
        second = (*stack)->next;

        first->next = second->next;
        second->next = first;
        second->prev = NULL;

        if (first->next != NULL)
        {
                first->next->prev = first;
        }

        *stack = second;
}
