#include "monty.h"

/**
 * function_add - Combines the top two elements on the stack.
 * @head: Pointer to the stack's head
 * @counter: Line number in the file
 * Return: No return value
 */
void function_add(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int stack_length = 0, result;

	current = *head;
	while (current)
	{
		current = current->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: Insufficient elements to perform addition\n", counter);
		fclose(bus.file);
		free(bus.content);
		f_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	result = current->n + current->next->n;
	current->next->n = result;
	*head = current->next;
	free(current);
}
