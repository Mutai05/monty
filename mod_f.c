#include "monty.h"

/**
 * function_mod - Computes the remainder of the division of the second
 * top element of the stack by the top element of the stack
 * @head: Pointer to the stack head
 * @counter: Line number in the Monty file
 * Return: No return value
 */
void function_mod(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: Cannot mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		f_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: Divide by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		f_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
