#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long int fib1 = 1, fib2 = 2, next_fib;
	int count = 2;

	printf("%lu, %lu", fib1, fib2);
	while (count <= 98)
	{
		next_fib = fib1 + fib2;
		printf(", %lu", next_fib);
		fib1 = fib2;
		fib2 = next_fib;
		count++;
	}
	printf("\n");

	return (0);
}
