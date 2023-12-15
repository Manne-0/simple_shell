#include "shell.h"

/**
 * _strchr - locate character instring
 * @s: pointer to the string
 * @c: character to find
 * Return: pointer to the first occurence of the character or NULL if not found
 */

char *_strchr(char *s, char c)
{
	if (s == NULL)
		return (NULL);

	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}

	if (*s == c)
		return (s);

	return (NULL);
}
