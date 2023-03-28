#include "main.h"
/**
 * _strlen - returns the length of a string
 * @s: the string whose length to calculate
 *
 * Return: length of s
 */
int _strlen(char *s)
{
int i = 0;

while (s[i] != '\0')
i++;
return (i);
}
