#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * prompt - display prompt to user for input
 * @input: pointer to input buffer
 * @input_size: pointer to the size of input buffer
 */

void prompt(char **input, size_t *input_size)
{
	ssize_t read;

	write(STDOUT_FILENO, "shell$ ", 7);
	read = getline(input, input_size, stdin);

	/*Handles EOF*/
	if (read == -1)
	{
		(*input)[0] = '\0';
	}
	else if ((*input)[read - 1] == '\n')
	{
		(*input)[read - 1] = '\0';
	}
}
