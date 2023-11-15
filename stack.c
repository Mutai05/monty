#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

#define UNUSED(x) (void)(x)

void push(int value, unsigned int line_number)
{
    UNUSED(line_number);

    stack_t *new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = stack;

    if (stack != NULL)
        stack->prev = new_node;

    stack = new_node;
}
