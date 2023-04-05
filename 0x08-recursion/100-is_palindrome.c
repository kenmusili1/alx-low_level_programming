#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * is_palindrome - Checks if a given string is a palindrome.
 *
 * @s: The string to check.
 *
 * Return: 1 if @s is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
int len = strlen(s);
int i;

    /* Base case: an empty string is a palindrome */
if (len == 0)
return (1);

    /* Check the first and last character of the string */
if (s[0] != s[len - 1])
return (0);

    /* If the first and last characters match, recurse on the substring
       that excludes the first and last characters */
s[len - 1] = '\0';
i = is_palindrome(s + 1);
s[len - 1] = s[0];

return (i);
}
