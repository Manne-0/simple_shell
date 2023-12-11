#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute - executes commands inputed
 * @input: user input
 */
void execute(char *input, char *programName)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		char *args[] = {input, NULL};
		execve(input, args, NULL);
		perror(programName);
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
	}
	else
	{
		perror(programName);
		exit(EXIT_FAILURE);
	}
}
