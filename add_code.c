#include "monty.h"

/**
 * f_add - Adds the top two elements of the stack.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void f_add(stack_t **head, unsigned int counter) {
    stack_t *temp;
    int length = 0, sum;

    temp = *head;
    while (temp) {
        temp = temp->next;
        length++;
    }
    if (length < 2) {
        fprintf(stderr, "L%d: Cannot add, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    temp = *head;
    sum = temp->n + temp->next->n;
    temp->next->n = sum;
    *head = temp->next;
    free(temp);
}
