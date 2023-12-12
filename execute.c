#include "shell.h"

void exe(char *command, char *programName)
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

	if (_strchr(args[0], '/') != NULL) {

        pid_t pid = fork();

        if (pid == 0) {
            execve(args[0], args, NULL);
            perror(programName);
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            waitpid(pid, NULL, 0);
        } else {
            perror(programName);
            exit(EXIT_FAILURE);
        }
    } else {

        char *path = _getenv("PATH");
        char *path_copy = _strdup(path);
        char *dir = strtok(path_copy, ":");

        while (dir != NULL) {
            char command_path[100];
            myprintf(command_path, sizeof(command_path), "%s/%s", dir, args[0]);

	    if (access(command_path, X_OK) == 0) {

                pid_t pid;
               pid = fork();

                if (pid == 0) {
                    execve(command_path, args, NULL);
                    perror(programName);
                    exit(EXIT_FAILURE);
                } else if (pid > 0) {
                    waitpid(pid, NULL, 0);
                    break;
                } else {
                    perror(programName);
                    exit(EXIT_FAILURE);
                }
            }

            dir = strtok(NULL, ":");
        }

        free(path_copy);

    }
}
