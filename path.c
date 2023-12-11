#include "shell.h"

char *path(const char *command)
{
	char *path = _getenv("PATH");
	char *pathCopy = strdup(path);
	char *directory = strtok(pathCopy, ":");

	while (directory != NULL)
	{
		char cmd_path[100];
		myprintf(cmd_path, "%s/%s", directory, command);

		if (access(cmd_path, X_OK) == 0)
		{
			free(pathCopy);
			return strdup(cmd_path);
		}

		directory(NULL, ":");
	}
	free(pathCopy);
	return (NULL);
}
