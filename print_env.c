#include "shell.h"

void print_env(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		size_t len = _strlen(*env);
		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);
	}
}
