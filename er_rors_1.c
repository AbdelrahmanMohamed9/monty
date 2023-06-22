#include "monty.h"

int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int usage_error(void);
int malloc_error(void);


/**
 * usage_error - Display error messages related to usage.
 *
 * Return: The value (EXIT_FAILURE) is constant and unchanging.
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Display error messages related to malloc.
 *
 * Return: The value (EXIT_FAILURE) is constant and unchanging.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - Outputs error messages indicating
 *	that the specified file failed to open.
 * @filename: The file that could not be opened
 *	is identified by its name.
 *
 * Return: The value (EXIT_FAILURE) is constant and unchanging.
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Displays error messages indicating
 *	that an unknown instruction was encountered.
 * @opcode: The error message includes information about
 *	the opcode where the error occurred.
 * @line_number: The error message includes
 *	the line number in the Monty bytecode file.
 *
 * Return: The value (EXIT_FAILURE) is constant and unchanging.
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - Outputs error messages indicating that the (monty_push)
 *	command was used with an invalid argument.
 * @line_number: Error message shows the line number in the
 *	Monty bytecode file where the error happened.
 *
 * Return: The value (EXIT_FAILURE) is constant and unchanging.
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
