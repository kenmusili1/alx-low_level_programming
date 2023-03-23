#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
int i;
unsigned long int a = 0, b = 1, next = 0;

for (i = 0; i <= 50; i++)
{
if (i == 0)
printf("%lu", b);
else
{
next = a + b;
printf(", %lu", next);
a = b;
b = next;
}
}

printf("\n");
return (0);
}
