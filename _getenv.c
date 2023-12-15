#include "shell.h"
#include <stdlib.h>
/**
 * _getenv - get value of environment variable
 * @name: name of environment variable
 * Return: value if found otherwise NULL
 */

char *_getenv(const char *name)
{
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
