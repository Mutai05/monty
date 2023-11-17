#include "monty.h"

/**
 * function_sub - Subtracts the top element of the stack from the second top element.
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */
void function_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int subtraction, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: Cannot sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		f_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	subtraction = aux->next->n - aux->n;
	aux->next->n = subtraction;
	*head = aux->next;
	free(aux);
}
