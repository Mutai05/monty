#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <string.h>

/**
 * struct stack_s - Represents a node in a doubly linked list for stack or queue
 * @n: Integer value stored in the node
 * @prev: Pointer to the previous node in the stack or queue
 * @next: Pointer to the next node in the stack or queue
 *
 * Description: Node structure for a doubly linked list used in stack or queue operations.
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Represents an opcode and its associated function
 * @opcode: The opcode as a string
 * @f: Pointer to the function that handles the opcode
 *
 * Description: Structure defining an opcode and its respective function for stack or queue operations.
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;

int _strcmp(char *opcode, char *list);
void add(stack_t **stack, unsigned int line_num);
void _swap(stack_t **doubly, unsigned int cline);
void pall(stack_t **stack, unsigned int line_num);
void execute(char *string[], stack_t *stack);
void _pint(stack_t **doubly, unsigned int cline);
void free_stack(stack_t *head);
void _pop(stack_t **doubly, unsigned int cline);
int pushint(char *list, int ln);
void push(stack_t **stack, unsigned int line_number, int n);
void _pchar(stack_t **doubly, unsigned int cline);
int nlfind(char *list);
void free_list(char *a[]);
int combfind(char *list, int ln);

#endif
