#include "monty.h"

/**
 * function_pall - Print all elements in the stack.
 * @head: Pointer to the head of the stack
 * @counter: Unused variable
 * Return: No return value
 */
void function_pall(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	/* Traverse the stack and print each element */
	current = *head;
	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
