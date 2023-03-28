/**
 * _atoi - convert a string to an integer
 *
 * @s: the string to convert
 *
 * Return: the converted integer
 */
int _atoi(char *s)
{
int result = 0;
int sign = 1;
int digit;

while (*s != '\0')
{
if (*s == '-')
{
sign *= -1;
}
else if (*s == '+')
{
/* do nothing, just keep the sign positive */
}
else if (*s >= '0' && *s <= '9')
{
digit = *s - '0';
result = "result * 10 + sign * digit";
}
else if (result != 0)
{
/* end of the number, stop parsing */
break;
}

s++;
}

return (result);
}
