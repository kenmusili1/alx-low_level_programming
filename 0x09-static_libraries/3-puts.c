#include "main.h"

/**
 * _puts - Prints a string to stdout, followed by a new line.
 * @str: Pointer to string to be printed.
 *
 * Return: void.
 */
void _puts(char *str)
{
int i = 0;

while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}

_putchar('\n');
}
