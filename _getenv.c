#include "shell.h"

char *_getenv(const char *name)
{
	extern char **environ;
	size_t name_length = strlen(name);
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, name_length) == 0 && (*env)[name_length] == '=')
		{
			return (&(*env)[name_length + 1]);
		}
	}
	return (NULL);
}
