#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints the content of a buffer
 *
 * @b: pointer to the buffer to print
 * @size: size of the buffer
 *
 * Return: void
 */
void print_buffer(char *b, int size)
{
	int i, j;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);

		for (j = 0; j < 10; j++)
		{
			if (j + i < size)
			{
				printf("%02x", b[j + i]);
			}
			else
			{
				printf("  ");
			}

			if (j % 2 == 1)
			{
				printf(" ");
			}
		}

		for (j = 0; j < 10; j++)
		{
			if (j + i < size)
			{
				if (b[j + i] >= 32 && b[j + i] <= 126)
				{
					printf("%c", b[j + i]);
				}
				else
				{
					printf(".");
				}
			}
		}

		printf("\n");
	}
}
