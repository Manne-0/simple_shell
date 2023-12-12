#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string to be counted
 * Return: the length of the checked string
 */

int _strlen(char *s)
{
        int length = 0;

        while (s[length])
                length++;
        return (length);
}
