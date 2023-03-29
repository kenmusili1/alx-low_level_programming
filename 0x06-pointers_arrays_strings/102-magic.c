#include <stdio.h>

/**
 * main - prints the value of an int array
 *
 * Return: Always 0.
 */
int main(void)
{
int a[5] = {98, 102, 402, 204, 98};
int *p;

p = &a[0];
printf("a[2] = %d\n", *(p + 2)); /* added line */
printf("Value of p: %p\n", p);
p++;
printf("Value of p: %p\n", p);
printf("Value of *p: %d\n", *p);
printf("Value of *(p+1): %d\n", *(p + 1));
printf("Value of *(p+2): %d\n", *(p + 2));
printf("Value of *(p+3): %d\n", *(p + 3));
printf("Value of *(p+4): %d\n", *(p + 4));
return (0);
}
