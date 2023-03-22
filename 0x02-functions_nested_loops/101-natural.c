#include <stdio.h>

/**
 * main - Entry point
 * A program that prints and computes multiple numbers
 * return: Always 0
 */

int main(void)
{
int sum = 0;

for (int i = 0; i < 1024; i++)
{
if (i % 3 == 0 || i % 5 == 0)
{
sum += i;
}
}

printf("%d\n", sum);

return (0);
}
