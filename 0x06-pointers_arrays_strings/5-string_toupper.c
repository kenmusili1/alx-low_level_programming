/**
 * string_toupper - Changes all lowercase letters of a string to uppercase.
 *
 * @str: Pointer to a string.
 *
 * Return: Pointer to the resulting string.
 */
char *string_toupper(char *str)
{
char *ptr = str;

while (*ptr != '\0')
{
if (*ptr >= 'a' && *ptr <= 'z')
{
*ptr -= 32;
}
ptr++;
}

return (str);
}
