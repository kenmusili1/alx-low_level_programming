/**
 * rot13 - applies the rot13 encryption to a string
 * @s: the string to encrypt
 *
 * Return: a pointer to the encrypted string
 */
char *rot13(char *s)
{
	char *p = s;

	while (*p != '\0')
	{
		if ((*p >= 'A' && *p <= 'M') || (*p >= 'a' && *p <= 'm'))
		{
			*p += 13;
		}
		else if ((*p >= 'N' && *p <= 'Z') || (*p >= 'n' && *p <= 'z'))
		{
			*p -= 13;
		}
		p++;
	}

	return (s);
}
