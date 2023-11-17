#include "monty.h"

/**
 * function_mul - Multiplies the top two elements of the stack.
 * @head: Pointer to the head of the stack
 * @counter: Line number in the file
 * Return: No return value
 */
void function_mul(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int node_count = 0, result;

	current = *head;
	while (current)
	{
		current = current->next;
		node_count++;
	}

	if (node_count < 2)
	{
		fprintf(stderr, "L%d: Cannot multiply, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		f_free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	result = current->next->n * current->n;
	current->next->n = result;
	*head = current->next;
	free(current);
}
