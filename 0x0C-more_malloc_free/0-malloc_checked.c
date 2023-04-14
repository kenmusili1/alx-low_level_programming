#include <stdlib.h>

/**
 * malloc_checked - allocates memory using malloc
 * @b: the number of bytes to allocate
 *
 * Return: a pointer to the allocated memory
 *         if malloc fails the function terminates the program
 */
void *malloc_checked(unsigned int b)
{
	void *p = malloc(b);

	if (p == NULL)
		exit(98);

	return (p);
}
