#include "main.h"

/**
 * print_triangle - prints a triangle of a given size
 * @size: size of the triangle to be printed
 */
void print_triangle(int size)
{
int i, j;

if (size <= 0)
{
_putchar('\n');
return;
}

for (i = 0; i < size; i++)
{
for (j = size - i; j > 1; j--)
{
_putchar(' ');
}
for (j = 0; j <= i; j++)
{
_putchar('#');
}
_putchar('\n');
}
}
