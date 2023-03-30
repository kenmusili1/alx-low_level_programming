#include <stdio.h>

/**
* main - prints a[2] = 98, followed by a new line
* Return: Always 0.
*/
int main(void)
{
int a[5];
int *p;

a[2] = 1024;
p = &a[2];

/* write your code here */
printf("a[2] = %d\n", *(p));

return (0);
}
