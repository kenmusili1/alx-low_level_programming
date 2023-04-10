#include <stdio.h>

/**
 * main - Prints the number of arguments passed into the program
 * @argc: The number of arguments
 * @argv: An array containing the arguments
 *
 * Return: 0 if successful
 */
int main(int argc, char **argv)
{
	(void) argv; /*Ignore argv*/
	printf("%d\n", argc - 1);
	return (0);
}
