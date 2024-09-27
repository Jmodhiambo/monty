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


        if (current == NULL)
        {
                printf("Stack is empty.\n");
                return;
        }
        while (current != NULL)
        {
                printf("%d\n", current->n);
                current = current->next;
        }
}
