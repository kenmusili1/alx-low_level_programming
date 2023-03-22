#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0.
 * @n: number of times table
 *
 * Return: void
 */

void print_times_table(int n)
{
int num, mult, prod;

if (n < 0 || n > 15)
return;

for (num = 0; num <= n; num++)
{
for (mult = 0; mult <= n; mult++)
{
prod = num * mult;

if (mult != 0)
{
_putchar(',');
_putchar(' ');
if (prod < 100)
_putchar(' ');
if (prod < 10)
_putchar(' ');
}
if (prod >= 100)
_putchar((prod / 100) + '0');
if (prod >= 10)
_putchar(((prod / 10) % 10) + '0');
_putchar((prod % 10) + '0');
}
_putchar('\n');
}
}
