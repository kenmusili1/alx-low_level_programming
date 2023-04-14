#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the maximum number of bytes from s2 to concatenate
 *
 * Return: a pointer to the newly allocated concatenated string,
 *         or NULL if the allocation fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = s1 ? strlen(s1) : 0;
	unsigned int len2 = s2 ? strlen(s2) : 0;
	unsigned int len = len1 + (n >= len2 ? len2 : n);
	char *result = malloc(len + 1);

	if (result == NULL)
		return (NULL);

	if (len1 > 0)
		memcpy(result, s1, len1);

	if (n >= len2)
		memcpy(result + len1, s2, len2);
				else
					memcpy(result + len1, s2, n);

				result[len] = '\0';

				return (result);
}
