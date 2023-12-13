#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0 on success
 */

int main(int argc, char *argv[])
{
	char *input;
	size_t input_size;
	(void)argc;

	input = NULL;
	input_size = 0;

	while (1)
	{
		prompt(&input, &input_size);

		if (input[0] == '\0')
			break;
		/*execute_cmd(input, argv[0]);*/

		exe(input, argv[0]);
	}
	free(input);
	return (0);
}
