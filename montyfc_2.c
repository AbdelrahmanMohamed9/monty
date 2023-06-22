#include "monty.h"

void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);

/**
 * monty_add - Performs addition on the top
 *	two values of a stack_t linked list.
 * @stack: the pointer to the head node of a stack_t linked list.
 * @line_number: The line number currently being
 *	executed in a Monty bytecode file.
 *
 * Description: The sum of the top two values is placed in
 *	the second node from the top, and the top node is removed.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - Computes the difference between the top value
 *	and the second value from the top of a stack_t linked list.
 * @stack: the pointer to the head node of a stack_t linked list.
 * @line_number: The line number currently being
 *	executed in a Monty bytecode file.
 *
 * Description: The sum of the top two values is placed in
 *	the second node from the top, and the top node is removed.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - Computes the quotient obtained by dividing the top value
 *	of a stack_t linked list by the second value from the top.
 * @stack: the pointer to the head node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The sum of the top two values is placed in the second
 *	node from the top, and the top node is removed.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - Computes the product obtained by multiplying the second
 *	value from the top of a stack_t linked list by the top value.
 * @stack: the pointer to the head node of a stack_t linked list.
 * @line_number: The line number currently being
 *	executed in a Monty bytecode file.
 *
 * Description: The sum of the top two values is placed in the second
 *	node from the top, and the top node is removed.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - Calculates the remainder obtained by dividing the second
 *	value from the top of a stack_t linked list by the top value.
 * @stack: the pointer to the head node of a stack_t linked list.
 * @line_number: The line number currently being
 *	executed in a Monty bytecode file.
 *
 * Description: The product of the top two values is placed in
 *	the second node from the top, and the top node is removed.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}
