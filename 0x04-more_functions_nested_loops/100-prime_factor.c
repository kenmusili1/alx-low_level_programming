#include <stdio.h>
#include <math.h>

/**
 * main - Entry point
 *
 * Description: Finds and prints the largest prime factor
 * of the number 612852475143, followed by a new line.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
unsigned long int num = 612852475143, i;

for (i = 2; i <= num; i++)
{
if (num % i == 0)
{
while (num % i == 0)
{
num /= i;
}
if (num == 1 || num == i)
{
printf("%lu\n", i);
break;
}
}
}

return (0);
}
