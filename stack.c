#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @ac: Number of arguments passed
 * @av: Array of arguments passed to the program
 * Return: Always returns 0 upon successful execution
 */
int main(int ac, char *av[])
{
    stack_t *stack = NULL;
    static char *string[1000] = {NULL};
    int n = 0;
    FILE *fd;
    size_t bufsize = 1000;

    if (ac != 2)
    {
        fprintf(stderr, "USE: Monty file\n");
        exit(EXIT_FAILURE);
    }
    fd = fopen(av[1], "r");
    if (fd == NULL)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }

    for (n = 0; getline(&(string[n]), &bufsize, fd) > 0; n++)
        ;
    execute(string, stack);
    free_list(string);
    fclose(fd);
    return (0);
}

/**
 * execute - Executes Monty opcodes
 * @string: Array containing the contents of the file
 * @stack: Pointer to the stack (doubly linked list)
 * Return: void
 */
void execute(char *string[], stack_t *stack)
{
    int ln, n, i;

    instruction_t st[] = {
        {"pall", pall},
        {"pint", pint},
        {"add", add},
        {"swap", swap},
        {"pop", pop},
        {"n/a", NULL}};

    for (ln = 1, n = 0; string[n + 1]; n++, ln++)
    {
        if (_strcmp("push", string[n]))
            push(&stack, ln, pushint(string[n], ln));
        else if (_strcmp("nop", string[n]))
            ;
        else
        {
            i = 0;
            while (!_strcmp(st[i].opcode, "n/a"))
            {
                if (_strcmp(st[i].opcode, string[n]))
                {
                    st[i].f(&stack, ln);
                    break;
                }
                i++;
            }
            if (_strcmp(st[i].opcode, "n/a") && !_strcmp(string[n], "\n"))
            {
                fprintf(stderr, "L%u: Invalid instruction %s", ln, string[n]);
                if (!nlfind(string[n]))
                    fprintf(stderr, "\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    free_stack(stack);
}
