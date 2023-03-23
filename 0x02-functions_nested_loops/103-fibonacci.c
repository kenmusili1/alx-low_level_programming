#include <stdio.h>

/**
 * main - Fibonacci sequence
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
unsigned long int sum = 0, a = 0, b = 1, temp;

while (b <= 4000000)
{
temp = a + b;
a = b;
b = temp;
if (b % 2 == 0)
sum += b;
}
printf("%lu\n", sum);
return (0);
}
