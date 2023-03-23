#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
int count = 50;
unsigned long long first = 1, second = 2, next;

printf("%llu, %llu, ", first, second);

for (int i = 2; i < count; i++)
{
next = first + second;
printf("%llu", next);
if (i < count - 1)
{
printf(", ");
}
first = second;
second = next;
}

printf("\n");

return (0);
}
