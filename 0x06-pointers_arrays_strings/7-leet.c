/**
 * leet - encodes a string into 1337.
 * @str: the string to be encoded
 *
 * Return: pointer to the encoded string
 */
char *leet(char *str)
{
char *p = str;
char *leet_chars = "aAeEoOtTlL";
char *leet_subs = "44337011";
int i;

while (*p != '\0')
{
for (i = 0; leet_chars[i] != '\0'; i++)
{
if (*p == leet_chars[i])
{
*p = leet_subs[i];
break;
}
}
p++;
}

return (str);
}
