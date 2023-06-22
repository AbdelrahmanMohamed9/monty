#include "monty.h"
#include <string.h>

int check_mode(stack_t *stack);
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);

/**
 * check_mode - Function Checks if stack_t linked list is in stack
 * or in queue mode.
 * @stack: pointer to top (stack) or bottom (queue)
 * of a stack_t linked list.
 * Return: (0) if stack_t is in stack mode - STACk.
 * or (1) If stack_t is in queue mode - QUEUE.
 * Otherwise return 2.
 */

int check_mode(stack_t *stack)
{
	if (stack->n == QUEUE)
		return (QUEUE);
	else if (stack->n == STACK)
		return (STACK);
	return (2);
}

/**
 * free_stack - Function Frees stack_t stack.
 * @stack: pointer to the top (stack) or
 * the bottom (queue) of stack_t.
 */

void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * init_stack - Function Initializes stack_t stack with
 * the beginning stack and ending queue nodes.
 * @stack: pointer to unitialized stack_t stack.
 * Return: EXIT_FAILURE if an error occurs
 * Otherwise - EXIT_SUCCESS.
 */

int init_stack(stack_t **stack)
{
	stack_t *tmp_stack;

	tmp_stack = malloc(sizeof(stack_t));
	if (tmp_stack == NULL)
		return (malloc_error());

	tmp_stack->n = STACK;
	tmp_stack->prev = NULL;
	tmp_stack->next = NULL;

	*stack = tmp_stack;

	return (EXIT_SUCCESS);
}
