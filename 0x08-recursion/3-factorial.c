#include "main.h"

/**
 * factorial - Computes the factorial of a given number using recursion.
 * @n: The number to compute the factorial of.
 *
 * Return: The factorial of n, or -1 if n is negative (error).
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));
}
