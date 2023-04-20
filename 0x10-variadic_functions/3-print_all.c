#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>

/**
 * print_all - prints anything.
 * @format: list of types of arguments passed to the function
 *
 * Description: c: char, i: integer, f: float, s: char * (if the string is NULL, print (nil) instead.
 * any other char should be ignored. see example
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	va_list arg_list;
	int i = 0;
	char *str;

	va_start(arg_list, format);

	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(arg_list, int));
				break;
			case 'i':
				printf("%d", va_arg(arg_list, int));
				break;
			case 'f':
				printf("%f", va_arg(arg_list, double));
				break;
			case 's':
				str = va_arg(arg_list, char *);
				if (str == NULL)
					printf("(nil)");
				else
					printf("%s", str);
				break;
			default:
				i++;
				continue;
		}
		if (format[i + 1] != '\0')
			printf(", ");
		i++;
	}

	printf("\n");
	va_end(arg_list);
}
