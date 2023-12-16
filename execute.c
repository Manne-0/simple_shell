#include "shell.h"
#include <limits.h>
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

	if (args[0] != NULL && _strchr(args[0], '/') != NULL)
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
	int i = 0;
	char num_buf[16];
	int len;

	pid_t pid = fork();

	if (pid == 0)
	{
		execve(args[0], args, environ);
		write(STDERR_FILENO, programName, strlen(programName));
		write(STDERR_FILENO, ": ", 2);

		while (args[i] != NULL)
			i++;

		len = sprintf(num_buf, "%d", i + 1);

		write(STDERR_FILENO, num_buf, len);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, args[0], strlen(args[0]));
		write(STDERR_FILENO, ": not found\n", 12);

		exit(2);
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
	}
	else
	{
		write(STDERR_FILENO, programName, strlen(programName));
		write(STDERR_FILENO, ": ", 2);
		perror(args[0]);
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
	char command_path[PATH_MAX];

	if (path == NULL)
	{
		perror("PATH not found");
		return;
	}

	while (dir != NULL)
	{
		size_t len = _strlen(dir) + _strlen(args[0]) + 2;

		if (len <= 100)
		{
			_strcpy(command_path, dir);
			_strcat(command_path, "/");
			_strcat(command_path, args[0]);

			if (access(command_path, X_OK) == 0)
			{
				execute_direct_path(args, programName);
				break;
			}
		}

		dir = strtok(NULL, ":");
	}
	free(path_copy);
}
