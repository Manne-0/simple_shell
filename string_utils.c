#include "shell.h"
/**
 * _strdup - Duplicate a string
 * @s: string to duplicate
 * Return: pointer to newly allocated dup string
 */

char *_strdup(const char *s)
{
	size_t len = _strlen(s) + 1;
	char *dup = malloc(len);

	if (dup != NULL)
	{
		_strcpy(dup, s);
	}
	return (dup);
}

/**
 * _strlen - Calculate the length of a string
 * @s: input string
 * Return: length of the string
 */

size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcpy - Copy a string from source to destination
 * @dest: destination buffer
 * @src: source string
 * Return: pointer to destination  buffer
 */

char *_strcpy(char *dest, const char *src)
{
	size_t i = 0;

	while ((dest[i] = src[i]) != '\0')
	{
		i++;
	}
	return (dest);
}

/**
 * _strcat - Concatenate two strings
 * @dest: destination buffer
 * @src: surce string to be concatenated
 * Return: Pointer to the destination buffer
 */

char *_strcat(char *dest, const char *src)
{
	size_t dest_len = _strlen(dest);
	size_t i = 0;

	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}

	dest[dest_len + i] = '\0';
	return (dest);
}
