#include "monty.h"

void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);

/**
 * monty_stack - function Converts queue to stack.
 * @stack: pointer to top node of stack_t linked list.
 * @line_number: current working line number of Monty bytecodes file.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - function Converts stack to queue.
 * @stack: pointer to top node of stack_t linked list.
 * @line_number: current working line number of Monty bytecodes file.
 */

void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}


/**
 * monty_rotl - function Rotates top value of a stack_t linked list to bottom.
 * @stack: pointer to top node of stack_t linked list.
 * @line_number: current working line number of Monty bytecodes file.
 */

void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top_value, *bottom_value;

	if ((*stack)->next->next == NULL || (*stack)->next == NULL)
		return;

	top_value = (*stack)->next;
	bottom_value = (*stack)->next;
	while (bottom_value->next != NULL)
		bottom_value = bottom_value->next;

	top_value->next->prev = *stack;
	(*stack)->next = top_value->next;
	bottom_value->next = top_value;
	top_value->next = NULL;
	top_value->prev = bottom_value;

	(void)line_number;
}

/**
 * monty_rotr - function Rotates bottom value of stack_t linked list to top.
 * @stack: pointer to top node of stack_t linked list.
 * @line_number: current working line number of Monty bytecodes file.
 */

void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top_value, *bottom_value;

	if ((*stack)->next->next == NULL || (*stack)->next == NULL)
		return;

	top_value = (*stack)->next;
	bottom_value = (*stack)->next;
	while (bottom_value->next != NULL)
		bottom_value = bottom_value->next;

	bottom_value->prev->next = NULL;
	(*stack)->next = bottom_value;
	bottom_value->prev = *stack;
	bottom_value->next = top_value;
	top_value->prev = bottom_value;

	(void)line_number;
}
