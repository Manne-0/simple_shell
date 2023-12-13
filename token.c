#include "shell.h"
/**
 * tokenize - split command string into array of tokens
 * @command: input command string to be tokenized
 * @args: array to store tge resulting tokens
 */

void tokenize(char *command, char **args)
{
	char *token = strtok(command, " \n");
	int i = 0;

	while (token != NULL && i < 99)
	{
		args[i++] = token;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;
}
