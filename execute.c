#include "shell.h"
/**
  * execute - execute a given command
  * @command: command to be excuted
  * @programName: name of the program
  */

void execute(char *command, char *programName)
{
	char *args[100];
	char *token = strtok(command, " ");

	int i = 0;

	while (token != NULL && i < 100 - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (_strchr(args[0], '/') != NULL)
		execute_direct_path(args, programName);
	else
		execute_path_resolution(args, programName);
}

/**
 * execute_direct_path - execute command when a path is given
 * @args: argument for the command
 * @programName: name of program
 */

void execute_direct_path(char *args[], char *programName)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		execve(args[0], args, NULL);
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

/**
 * execute_path_resolution - execute command after resolving path from variable
 * @args: argument for the command
 * @programName: name of program
 */

void execute_path_resolution(char *args[], char *programName)
{
	char *path = _getenv("PATH");
	char *path_copy = _strdup(path);
	char *dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		char command_path[100];

		myprintf(command_path, sizeof(command_path), "%s/%s", dir, args[0]);
		if (access(command_path, X_OK) == 0)
		{
			execute_direct_path(args, programName);
			break;
		}

		dir = strtok(NULL, ":");
	}

	free(path_copy);
}
