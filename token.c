#include "shell.h"

void tokenize(char *command, char **args)
{
	char *token = strtok(command, " /n");
	int i = 0;

	while (token != NULL && i < 99)
	{
		args[i++] = token;
		token = strtok(NULL, " /n");
	}
	args[i] = NULL;
}
