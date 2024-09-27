#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the stack_t structure */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/* Function to push a value onto the stack */
void push(stack_t **stack, int value)
{
        stack_t *new_node;

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
        {
                (*stack)->prev = new_node;
        }

        *stack = new_node;
        printf("Pushed value: %d\n", value);
        printf("Stack top is now: %d\n", (*stack)->n);
}

/* Function to print all elements in the stack */
void pall(stack_t **stack, unsigned int line_number)
{
        stack_t *current = *stack;

        (void)line_number; /* Unused parameter */

        if (current == NULL)
        {
                printf("Stack is empty.\n");
                return;
        }

        printf("Printing stack from top to bottom:\n");
        while (current != NULL)
        {
                printf("%d\n", current->n);
                current = current->next;
        }
}

/* Test the push and pall functions */
int main(void)
{
        stack_t *stack = NULL;

        /* Variables to store values */
        char *arg;
        int value;

        /* Push different values onto the stack */
        arg = "1"; // Simulate input argument
        value = atoi(arg); // Convert to integer
        push(&stack, value); // Push 1
        pall(&stack, 1); // Print stack

        arg = "2"; // Simulate input argument
        value = atoi(arg); // Convert to integer
        push(&stack, value); // Push 2
        pall(&stack, 1); // Print stack

        arg = "3"; // Simulate input argument
        value = atoi(arg); // Convert to integer
        push(&stack, value); // Push 3
        pall(&stack, 1); // Print stack

        return 0;
}

