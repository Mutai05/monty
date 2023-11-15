#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void push(int value, unsigned int line_number)
{
    stack_t *new_node;

    (void)line_number;  /* Mark line_number as unused */

    new_node = malloc(sizeof(stack_t));

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

void pall(void)
{
    stack_t *current = stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
