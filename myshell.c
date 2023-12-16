#include "shell.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0 on success
 */

int main(int argc, char *argv[])
{
	char *input = NULL;
	size_t input_size = 0;

	(void)argc;

	while (1)
	{
		prompt(&input, &input_size);

		if (input[0] == '\0')
		{
			free(input);
			break;
		}

		if (strcmp(input, "exit") == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}

		if (strcmp(input, "env") == 0)
		{
			print_env();
			continue;
		}

		execute(input, argv[0]);
	}
	free(input);
	input = NULL;
}
