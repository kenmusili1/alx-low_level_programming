#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: The number of arguments passed
 * @argv: An array containing the arguments passed
 *
 * Return: 0 if successful, 1 if an error occurs
 */
int main(int argc, char *argv[])
{
	int sum = 0, i, j;

	if (argc < 2)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
