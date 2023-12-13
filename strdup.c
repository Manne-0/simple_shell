#include "shell.h"

/**
 * _strcpy - copies the string
 * @dest: buffer
 * @src: pointer of string to be copied
 * Return: dest
 */

char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @s: pointer to the string to be duplicated
 * Return: pointed to newly allocated dup string or NULL if it fails
 */

char *_strdup(const char *s)
{
	size_t len;
	char *new;

	if (s == NULL)
	{
		return (NULL);
	}

	len = _strlen(s);
	new = (char *)malloc(len + 1);

	if (new == NULL)
		return (NULL);

	_strcpy(new, s);
	return (new);
}
