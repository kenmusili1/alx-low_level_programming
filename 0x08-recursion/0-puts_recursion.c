#include "main.h"

/**
 * _puts_recursion - prints a string followed by a new line using recursion
 * @s: the string to print
 */
void _puts_recursion(char *s)
{
if (*s == '\0')
{
_putchar('\n');  /* Print a newline when the string is done */
return;
}

_putchar(*s);      /* Print the current character */
_puts_recursion(s + 1); /* Move to the next character and repeat */
}
