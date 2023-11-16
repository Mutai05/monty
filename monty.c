#include "monty.h"

/**
 * print_stack - Outputs all values in the stack
 * @stack: Pointer to the head of the stack
 * @line_num: Line number in the file
 * Return: Void
 */
void print_stack(stack_t **stack, unsigned int line_num)
{
    stack_t *h = *stack;
    (void)line_num;

    /* Output all values in the stack */
    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}

/**
 * push_to_stack - Adds an element to the stack
 * @stack: Pointer to the head of the stack
 * @line_num: Line number in the file
 * @n: Value to be pushed
 * Return: Address of the new element
 */
void push_to_stack(stack_t **stack, unsigned int line_num, int n)
{
    stack_t *new, *h = *stack;

    /* Validate if the stack is NULL */
    if (stack == NULL)
    {
        fprintf(stderr, "L%d: USE: Push integer", line_num);
        exit(EXIT_FAILURE);
    }

    /* Allocate memory for a new stack element */
    new = malloc(sizeof(stack_t));
    if (new == NULL)
        exit(EXIT_FAILURE);

    /* Initialize the new stack element */
    new->prev = NULL;
    new->n = n;
    new->next = *stack;
    if (*stack)
        h->prev = new;
    *stack = new;
}

/**
 * pop_from_stack - Removes the top element from the stack
 * @stack: Pointer to the head of the stack
 * @line_num: Line number in the file
 * Return: Void
 */
void pop_from_stack(stack_t **stack, unsigned int line_num)
{
    stack_t *h = *stack;

    /* Check if the stack is empty */
    if (!(*stack))
    {
        fprintf(stderr, "L%u: Cannot pop an empty stack\n", line_num);
        exit(EXIT_FAILURE);
    }

    /* Remove the top element from the stack */
    if (h)
    {
        *stack = (h)->next;
        free(h);
    }
}

/**
 * swap_stack_elements - Swaps the top two elements in the stack
 * @stack: Pointer to the head of the stack
 * @line_num: Line number in the file
 * Return: Void
 */
void swap_stack_elements(stack_t **stack, unsigned int line_num)
{
    stack_t *h = *stack, *ptr;

    /* Check if the stack has fewer than two elements */
    if ((*stack) == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: Cannot swap, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }

    /* Swap the top two elements in the stack */
    if (h && h->next)
    {
        ptr = h->next;
        if (ptr->next)
            ptr->next->prev = h;
        h->next = ptr->next;
        ptr->prev = NULL;
        ptr->next = h;
        h->prev = ptr;
        *stack = ptr;
    }
}
