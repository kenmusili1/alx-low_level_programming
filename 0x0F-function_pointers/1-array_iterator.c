#include "function_pointers.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * array_iterator - executes a function
 * @array: the array to iterate through
 * @size: the size of the array
 * @action: a pointer to the function to execute on each element of the array
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
unsigned int i;

if (array && action)
{
for (i = 0; i < size; i++)
(*action)(array[i]);
}
}
