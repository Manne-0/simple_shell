#include "shell.h"

/**
 * _strcmp - compares two string
 * @s1: firste string
 * @s2: second string
 * Return: 0
 */

int _strcmp(char *s1, char *s2)
{
        int compare;
        int i = 0;

        while (s1[i] == s2[i] && s1[i] != '\0')
        {
                i++;
        }
        compare = s1[i] - s2[i];
        return (compare);
}
