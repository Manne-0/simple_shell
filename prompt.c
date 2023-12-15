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

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "shell$ ", 7);
	}

	read = getline(input, input_size, stdin);

	/*Handles EOF*/
	if (read == -1)
	{
		if (feof(stdin))
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			free(*input);
			*input = NULL;
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			free(*input);
			*input = NULL;
			exit(EXIT_FAILURE);
		}
	}
	else if ((*input)[read - 1] == '\n')
	{
		(*input)[read - 1] = '\0';
	}
}
