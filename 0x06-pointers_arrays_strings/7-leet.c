/**
 * leet - encodes a string into 1337
 *
 * @str: string to be encoded
 *
 * Return: encode string
 */
char *leet(char *str)
{
	char arr[] = "a4A4e3E3o0O0t7T7l1L1";
	int i;
	int j;

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; arr[j] != '\0'; j++)
		{
			if (str[i] == arr[j])
			{
				str[i] = arr[j + 1];
				break;
			}
		}
	}
	return (str);
}
