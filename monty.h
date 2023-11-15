#ifndef MONTY_H
#define MONTY_H

/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Global variable representing the top of the stack */
extern stack_t *stack;

/* Function prototypes */
void push(int value, unsigned int line_number);
void pall(void);

#endif /* MONTY_H */
