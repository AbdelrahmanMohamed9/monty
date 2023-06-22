#define  _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <string.h>
#include <stdio.h>

unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void free_tokens(void);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);

/**
 * token_arr_len - Gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int token_arr_len(void)
{
	unsigned int toks_length = 0;

	while (op_toks[toks_length])
		toks_length++;
	return (toks_length);
}

/**
 * is_empty_line - function Checks if line read from getline
 * only contains delimiters.
 * @line: pointer to line.
 * @delims: string of delimiter characters.
 * Return: -1 If line only contains delimiters.
 * Otherwise -rerutn  0.
 */
int is_empty_line(char *line, char *delims)
{
	int a, b;

	for (a = 0; line[a]; a++)
	{
		for (b = 0; delims[b]; b++)
		{
			if (line[a] == delims[b])
				break;
		}
		if (delims[b] == '\0')
			return (0);
	}

	return (1);
}

/**
 * free_tokens - function Frees global op_toks array of strings.
 */

void free_tokens(void)
{
	size_t a = 0;

	if (op_toks == NULL)
		return;

	while (op_toks[a])
	{
		free(op_toks[a]);
		a++;
	}
	free(op_toks);
}

/**
 * get_op_func - Function Matches opcode with its
 * corresponding function.
 * @opcode: opcode to match.
 * Return: pointer to corresponding function.
 */

void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};
	int a = 0;

	while (op_funcs[a].opcode)
	{
		if (strcmp(opcode, op_funcs[a].opcode) == 0)
			return (op_funcs[a].f);
		a++;
	}

	return (NULL);
}

/**
 * run_monty - Function to execute Monty bytecodes script.
 * @script_fd: The File descriptor for open Monty bytecodes script.
 * Return: EXIT_SUCCESS on success or respective error code on failure.
 */

int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t length = 0, exit_status = EXIT_SUCCESS;
	unsigned int l_number = 0, prev_token_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &length, script_fd) != -1)
	{
		l_number++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (op_toks[0][0] == '#')
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_op_error(op_toks[0], l_number);
			free_tokens();
			break;
		}
		prev_token_len = token_arr_len();
		op_func(&stack, l_number);
		if (token_arr_len() != prev_token_len)
		{
			if (op_toks && op_toks[prev_token_len])
				exit_status = atoi(op_toks[prev_token_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}

	free(line);
	return (exit_status);
}
