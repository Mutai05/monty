#include "monty.h"

/**
 * function_pchar - Print the character at the top of the stack, followed by a new line.
 * @head: Pointer to the head of the stack
 * @counter: Line number
 * Return: No return value
 */
void function_pchar(stack_t **head, unsigned int counter)
{
	stack_t *top;

	top = *head;
	if (!top)
	{
		fprintf(stderr, "L%d: Cannot pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		f_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (top->n > 127 || top->n < 0)
	{
		fprintf(stderr, "L%d: Cannot pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		f_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}
