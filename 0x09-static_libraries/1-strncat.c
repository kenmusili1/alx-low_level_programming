/**
 * _strncat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * @n: maximum number of bytes from src to concatenate
 *
 * Return: a pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
int dest_len = 0;
char *dest_ptr = dest;

/* Find the end of the destination string */
while (*dest_ptr != '\0')
{
dest_ptr++;
dest_len++;
}

/* Append the source string up to n bytes */
while (*src != '\0' && n > 0)
{
*dest_ptr = *src;
dest_ptr++;
src++;
dest_len++;
n--;
}

/* Add the null-terminator */
if (dest_len < (int)sizeof(dest))
{
*dest_ptr = '\0';
}

return (dest);
}
