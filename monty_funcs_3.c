#include "monty.h"

void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - function Does nothing for Monty op code'nop'.
 * @stack: pointer to top node of stack_t linked list.
 * @line_number: current working line number of Monty bytecodes file.
 */

void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pstr - function Prints string contained in stack_t linked list.
 * @stack: pointer to top node of a stack_t linked list.
 * @line_number: current working line number of Monty bytecodes file.
 */

void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	while (temp && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");

	(void)line_number;
}

/**
 * monty_pchar - function Prints character in top value
 * node of stack_t linked list.
 * @stack: pointer to top node of a stack_t linked list.
 * @line_number: current working line number of Monty bytecodes file.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number,
					"stack empty"));
		return;
	}
	if ((*stack)->next->n > 127 || (*stack)->next->n < 0)
	{
		set_op_tok_error(pchar_error(line_number,
					     "value out of range"));
		return;
	}
	printf("%c\n", (*stack)->next->n);
}
