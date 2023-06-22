#include "monty.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

/**
 * main - entry point for the Monty Interp
 * @argc: count of arguments passed to the program
 * @argv: pointer array of char pointers to arguments
 * Return: (EXIT_SUCCESS) on success or (EXIT_FAILURE) on error
 */

int main(int argc, char **argv)
{
	char **p_tks = NULL;
	FILE *srp_fd = NULL;
	int x_cd = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	srp_fd = fopen(argv[1], "r");
	if (srp_fd == NULL)
		return (f_open_error(argv[1]));
	x_cd = run_monty(srp_fd);
	fclose(srp_fd);
	return (x_cd);
}
