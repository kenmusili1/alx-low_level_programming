#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * cap_string - capitalizes all words of a string
 * @s: the string to capitalize
 *
 * Return: pointer to the resulting string
 */
char *cap_string(char *s)
{
int i, j;
char separators[] = " \t\n,;.!?\"(){}";

for (i = 0; s[i]; i++)
{
/* capitalize current letter if it's the first in the string */
if (i == 0 && s[i] >= 'a' && s[i] <= 'z')
s[i] -= 'a' - 'A';

/* capitalize letter after a separator */
for (j = 0; separators[j]; j++)
{
if (s[i] == separators[j])
{
if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
s[i + 1] -= 'a' - 'A';
break;
}
}
}

return (s);
}
