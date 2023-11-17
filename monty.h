#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - Structure representing a doubly linked list for stacks/queues
 * @n: Integer value stored in each node
 * @prev: Pointer to the previous element in the list
 * @next: Pointer to the next element in the list
 *
 * Description: This structure defines a node in a doubly linked list
 * used for stack and queue operations.
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - Structure holding program data during execution
 * @arg: Value of an argument
 * @file: Pointer to the current monty file
 * @content: Content of a line in the file
 * @lifi: Flag to switch between stack and queue
 *
 * Description: This structure carries essential data throughout
 * the program's execution.
 */

typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;
extern bus_t bus;

/**
 * struct instruction_s - Structure representing an operation and its function
 * @opcode: Operation code
 * @f: Pointer to the function implementing the operation
 *
 * Description: This structure associates an operation code with its respective function.
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char *clean_line(char *content);
void function_push(stack_t **head, unsigned int number);
void function_pall(stack_t **head, unsigned int number);
void function_swap(stack_t **head, unsigned int counter);
void function_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void f_free_stack(stack_t *head);
void function_sub(stack_t **head, unsigned int counter);
void function_div(stack_t **head, unsigned int counter);
void function_pop(stack_t **head, unsigned int counter);
void function_mul(stack_t **head, unsigned int counter);
void function_queue(stack_t **head, unsigned int counter);
void function_add(stack_t **head, unsigned int counter);
void function_nop(stack_t **head, unsigned int counter);
void function_pchar(stack_t **head, unsigned int counter);
void function_pstr(stack_t **head, unsigned int counter);
void function_rotl(stack_t **head, unsigned int counter);
void function_mod(stack_t **head, unsigned int counter);
void function_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void add_node(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void function_stack(stack_t **head, unsigned int counter);
#endif
