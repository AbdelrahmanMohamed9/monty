#include "monty.h"

void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);

/**
 * monty_push - Inserts a value into a linked list of type stack_t.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The current line number
 *	being executed in a Monty bytecode file.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tp, *nw;
	int t;

	nw = malloc(sizeof(stack_t));
	if (nw == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}

	for (t = 0; op_toks[1][t]; t++)
	{
		if (op_toks[1][t] == '-' && t == 0)
			continue;
		if (op_toks[1][t] < '0' || op_toks[1][t] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	nw->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK)
	{
		tp = (*stack)->next;
		nw->prev = *stack;
		nw->next = tp;
		if (tp)
			tp->prev = nw;
		(*stack)->next = nw;
	}
	else
	{
		tp = *stack;
		while (tp->next)
			tp = tp->next;
		nw->prev = tp;
		nw->next = NULL;
		tp->next = nw;
	}
}

/**
 * monty_pall - Outputs the values in a stack_t linked list.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The line number that is currently
 *	being executed in a Monty bytecode file.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tp = (*stack)->next;

	while (tp)
	{
		printf("%d\n", tp->n);
		tp = tp->next;
	}
	(void)line_number;
}

/**
 * monty_pint - Outputs the value at the top of a stack_t linked list.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The line number that is currently
 *	being executed in a Monty bytecode file.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * monty_pop - Deletes the topmost element of a stack_t linked list.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The current line number
 *	being executed in a Monty bytecode file.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nxt = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}

	nxt = (*stack)->next->next;
	free((*stack)->next);
	if (nxt)
		nxt->prev = *stack;
	(*stack)->next = nxt;
}

/**
 * monty_swap - Exchanges the positions of the
 *	top two elements of a stack_t linked list.
 * @stack: A pointer to the topmost node of a stack_t linked list.
 * @line_number: The line number that is currently being
 *	executed in a Monty bytecode file.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}

	tp = (*stack)->next->next;
	(*stack)->next->next = tp->next;
	(*stack)->next->prev = tp;
	if (tp->next)
		tp->next->prev = (*stack)->next;
	tp->next = (*stack)->next;
	tp->prev = *stack;
	(*stack)->next = tp;
}
