#include "monty.h"

/**
 * is_integer - Checks if a string is a valid integer
 * @str: The string to check
 *
 * Return: 1 if it's an integer, 0 otherwise
 */
int is_integer(char *str)
{
        if (!str || *str == '\0')
                return (0);
        if (*str == '-' || *str == '+')
                str++;
        while (*str)
        {
                if (*str < '0' || *str > '9')
                        return (0);
                str++;
        }
        return (1);
}

/**
 * add_node - Adds a node to the top of the stack
 * @stack: Double pointer to the stack
 * @n: The integer to add
 *
 * Return: Pointer to the new node, or NULL on failure
 */
stack_t *add_node(stack_t **stack, int n)
{
        stack_t *new_node = malloc(sizeof(stack_t));

        if (!new_node)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }

        new_node->n = n;
        new_node->prev = NULL;
        new_node->next = *stack;

        if (*stack)
                (*stack)->prev = new_node;
        *stack = new_node;

        return (new_node);
}


/**
 * parse_line - Parses a line and executes the corresponding opcode.
 * @line: The line to parse.
 * @line_number: The current line number.
 *
 * Description: This function splits the line into the opcode and its argument,
 * and calls the corresponding function to handle the opcode.
 */
void parse_line(char *line, unsigned int line_number)
{
        char *opcode;
        stack_t *stack = NULL;
        instruction_t instructions[] = {
                {"push", push},
                {"pall", pall},
               	{"pint", pint},
		{"pop", pop},
	        {NULL, NULL}
        };
        int i = 0;

        opcode = strtok(line, " \n\t");
        if (opcode == NULL || opcode[0] == '#')
                return;

        while (instructions[i].opcode != NULL)
        {
                if (strcmp(opcode, instructions[i].opcode) == 0)
                {
                        instructions[i].f(&stack, line_number);
                        return;
                }
                i++;
        }

        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
}




/**
 * free_stack - Frees a stack
 * @stack: Double pointer to the stack
 */
void free_stack(stack_t **stack)
{
        stack_t *temp;

        while (*stack)
        {
                temp = *stack;
                *stack = (*stack)->next;
                free(temp);
        }
}

