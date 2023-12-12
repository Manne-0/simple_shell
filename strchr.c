#include "shell.h"
#include <stdio.h>

/**
 * _strchr - locates a character in a string
 * @s: The string to search in
 * @c: the character to search for
 * Return: s
 */

char *_strchr(char *s, char c)
{
        while (*s != '\0')
        {
                if (*s == c)
                        return (s);
                s++;
        }
        if (*s == c)
                return (s);
        return (NULL);
}
