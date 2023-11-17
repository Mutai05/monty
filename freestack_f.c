#include "monty.h"

/**
 * f_free_stack - Frees a doubly linked list
 * @head: Pointer to the head of the stack
 *
 * This function frees all the nodes in a doubly linked list
 * starting from the head.
 */
void f_free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
