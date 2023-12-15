#include "shell.h"
#include <stdlib.h>
/**
 * print_env - print current environment
 */

void print_env(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		size_t len = strlen(*env);

		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);
	}
}
