#include "main.h"

/**
 * puts_half - prints half of a string, followed by a new line
 * @str: the string to print
 *
 * Return: void
 */
void puts_half(char *str)
{
int len = 0, i, n;

/* calculate the length of the string */
while (str[len] != '\0')
len++;

/* calculate the number of characters to print */
n = (len % 2 == 0) ? len / 2 : (len + 1) / 2;

/* print the second half of the string */
for (i = n; i < len; i++)
_putchar(str[i]);

/* print a new line */
_putchar('\n');
}
