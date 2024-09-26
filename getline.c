#include "monty.h"

/**
 * _getline - Reads an entire line from a file stream.
 * @lineptr: Pointer to the buffer to store the line.
 * @n: Pointer to the size of the buffer.
 * @stream: File stream to read from.
 *
 * Return: The number of characters read, or -1 on failure.
 */
int _getline(char **lineptr, size_t *n, FILE *stream)
{
        size_t pos = 0;
        int c;

        if (*lineptr == NULL || *n == 0)
        {
                *n = 128; /* Initial buffer size */
                *lineptr = malloc(*n);
                if (*lineptr == NULL)
                        return -1;
        }

        while ((c = fgetc(stream)) != EOF)
        {
                if (pos + 1 >= *n)
                {
                        *n *= 2;
                        *lineptr = realloc(*lineptr, *n);
                        if (*lineptr == NULL)
                                return -1;
                }

                (*lineptr)[pos++] = c;

                if (c == '\n')
                        break;
        }

        if (pos == 0 && c == EOF)
                return -1;

        (*lineptr)[pos] = '\0';
        return pos;
}

