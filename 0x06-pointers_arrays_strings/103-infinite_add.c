/**
 * infinite_add - Adds two numbers
 * @n1: First number
 * @n2: Second number
 * @r: Buffer to store result
 * @size_r: Size of buffer r
 *
 * Return: Pointer to the result or 0 if result can't be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
int i, j, k, l, m, n, sum, carry = 0;

for (l = 0; n1[l] != '\0'; l++)
	;
for (m = 0; n2[m] != '\0'; m++)
	;
if (l + 2 > size_r || m + 2 > size_r)

	return (0);
for (i = l - 1, j = m - 1, k = 0; i >= 0 || j >= 0 || carry; i--, j--, k++)
{
sum = carry;
if (i >= 0)
sum += n1[i] - '0';
if (j >= 0)
sum += n2[j] - '0';
carry = sum / 10;
r[k] = (sum % 10) + '0';
}
r[k--] = '\0';
for (n = 0; n < k; n++, k--)
{
r[n] ^= r[k];
r[k] ^= r[n];
r[n] ^= r[k];
}
return (r);
}
