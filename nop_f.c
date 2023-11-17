#include "monty.h"

/**
 * function_nop - No operation, does nothing.
 * @head: Pointer to the head of the stack
 * @counter: Line number in the file
 * Return: No return value
 */
void function_nop(stack_t **head, unsigned int counter)
{
  /* Does nothing, just acknowledging parameters */
  (void)counter;
  (void)head;
}
