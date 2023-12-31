#include "monty.h"

/**
 * function_pstr - Prints the string starting at the top of the stack.
 * @head: Pointer to the head of the stack
 * @counter: Line number
 * Return: No return value
 */
void function_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
