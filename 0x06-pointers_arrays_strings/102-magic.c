#include <stdio.h>

/**
 * main - prints a[2] = 98, followed by a new line
 * Return: Always 0.
 */
int main(void)
{
int a[5];
int *p;
int n[5] = {0, 1, 98, 3, 4};

a[2] = 1024;
p = &n[2];

printf("a[2] = %d\n", *(p));

return (0);
}
