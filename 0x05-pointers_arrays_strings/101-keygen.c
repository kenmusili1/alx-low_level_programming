#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * main - Generates random valid passwords for 101-crackme
 *
 * Return: Always 0.
 */
int main(void)
{
int i, sum, r;
char password[84];

srand(time(NULL));

sum = 0;
for (i = 0; i < 9; i++)
{
r = rand() % 10;
password[i] = '0' + r;
sum += r;
}

password[i++] = '0' + ((2772 - sum) % 10);

for (; i < 83; i++)
{
r = rand() % 62;
if (r < 26)
password[i] = 'A' + r;
else if (r < 52)
password[i] = 'a' + (r - 26);
else
password[i] = '0' + (r - 52);
}

password[i] = '\0';

printf("%s", password);

return (0);
}
