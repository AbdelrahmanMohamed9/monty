#include "monty.h"

/**
 * set_op_tok_error - Function Sets the last element
 * of the op_toks to be error code.
 * @error_code: AN Integer to store as string in op_toks.
 */

void set_op_tok_error(int error_code)
{
	int toks_length = 0;
	int a;
	char *exit_string = NULL;
	char **new_tok = NULL;

	toks_length = token_arr_len();
	new_tok = malloc(sizeof(char *) * (toks_length + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	for (a = 0; a < toks_length; a++)
		new_tok[a] = op_toks[a];
	exit_string = get_int(error_code);
	if (!exit_string)
	{
		free(new_tok);
		malloc_error();
		return;
	}
	new_tok[a++] = exit_string;
	new_tok[a] = NULL;
	free(op_toks);
	op_toks = new_tok;
}
