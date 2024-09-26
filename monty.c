#include "monty.h"

/* Global stack pointer */
stack_t *stack = NULL;

/**
 * main - Entry point of the Monty interpreter
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char *argv[])
{
        FILE *file;
        char *line = NULL;
        size_t len = 0;
        unsigned int line_number = 0;

        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                return (EXIT_FAILURE);
        }

        file = fopen(argv[1], "r");
        if (file == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                return (EXIT_FAILURE);
        }

        while (_getline(&line, &len, file) != -1)  /* Use _getline instead of getline */
        {
                line_number++;
                parse_line(line, line_number);
        }

        free(line);
        fclose(file);
        free_stack(&stack);
        return (EXIT_SUCCESS);
}

