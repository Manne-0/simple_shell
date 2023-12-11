#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - entry point
 * eturn: always 0 on sucess.
 */

int main(int argc, char *argv[])
{
	char *input = NULL;
	size_t input_size = 0;

	while (1)
	{
		prompt(&input, &input_size);

		if (input[0] == '\0')
			break;
		execute(input, argv[0]);
	}
	free(input);
	return (0);
}
