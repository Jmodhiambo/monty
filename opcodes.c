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
	stack_t *new_node;

	if (!arg || !is_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
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
/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number in the bytecode file.
 *
 * Description: If the stack is empty, an error message is printed
 *              and the program exits with status EXIT_FAILURE.
 */
void pint(stack_t **stack, unsigned int line_number)
{
        if (*stack == NULL)
        {
                fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
                exit(EXIT_FAILURE);
        }
        printf("%d\n", (*stack)->n);
}
/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number where the opcode appears
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
        stack_t *temp;

        if (*stack == NULL)
        {
                fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
                exit(EXIT_FAILURE);
        }

        temp = *stack;
        *stack = (*stack)->next;

        if (*stack != NULL)
                (*stack)->prev = NULL;

        free(temp);
}
/**
 * nop - Does nothing.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number where the opcode is found.
 */
void nop(stack_t **stack, unsigned int line_number)
{
        (void)stack;        /* Unused parameter */
        (void)line_number;  /* Unused parameter */
}
