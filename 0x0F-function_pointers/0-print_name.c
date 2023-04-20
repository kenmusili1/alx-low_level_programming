#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - prints a name using a given printing function
 *
 * @name: pointer to the name string to be printed
 * @f: pointer to the function that will print the name
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}
