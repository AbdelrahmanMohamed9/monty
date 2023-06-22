#include "monty.h"

int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);

/**
 * pop_error - Displays error messages indicating that
 *	a (pop) operation was attempted on an empty stack.
 * @line_number: The error message specifies the line
 *	number in the script where the error occurred.
 *
 * Return: The value (EXIT_FAILURE) is constant and unchanging.
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can not pop the empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - Outputs error messages indicating that
 *	a "pint" operation was attempted on an empty stack.
 * @line_number: The error message specifies the line number
 *	within the Monty bytecode file where the error occurred.
 *
 * Return: The value (EXIT_FAILURE) is constant and unchanging.
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can not pint, the stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - Displays error messages indicating that a Monty math
 *	function was attempted on a stack or queue with less than two nodes.
 * @line_number: Error message indicates the line number within
 *	the Monty bytecode file where the error occurred.
 * @op: The error message specifies the operation where the error occurred.
 *
 * Return: The value (EXIT_FAILURE) is constant and unchanging.
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can not %s, the stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - Displays error messages indicating that
 *	a division operation was attempted with a divisor of 0.
 * @line_number: The error message specifies the line number
 *	within the Monty bytecode file where the error occurred.
 *
 * Return: The value (EXIT_FAILURE) is constant and unchanging.
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by 0\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - Outputs error messages indicating that a (pchar) operation
 *	was attempted on an empty stack or with a non-character value.
 * @line_number: The error message specifies the line number within
 *	the Monty bytecode file where the error occurred.
 * @message: The error message to be printed is identified accordingly.
 *
 * Return: The value (EXIT_FAILURE) is constant and unchanging.
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can not pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
