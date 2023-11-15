#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stack_t *stack;  // Global variable representing the top of the stack

int main(int argc, char *argv[])
{
    // ...

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    char opcode[256];
    int value, line_number = 0;

    while (fscanf(file, "%s", opcode) != EOF)
    {
        line_number++;

        if (strcmp(opcode, "push") == 0)
        {
            if (fscanf(file, "%d", &value) == 1)
                push(value, line_number);
            else
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall();
        }
        // Add more opcode implementations here

        // ...
    }

    // ...

    return (EXIT_SUCCESS);
}
