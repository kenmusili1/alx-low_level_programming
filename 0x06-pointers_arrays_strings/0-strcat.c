
/**
 * main- function that concatenates two strings
 * @src- source string
 * @dest-destination string
 * return: pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
int dest_len = 0;
int i;

/* Find the length of the destination string */
while (dest[dest_len] != '\0')
dest_len++;

/* Append the source string to the destination string */
for (i = 0; src[i] != '\0'; i++)
dest[dest_len + i] = src[i];

/* Add the terminating null byte */
dest[dest_len + i] = '\0';

return (dest);
}
