#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count the words in
 *
 * Return: The number of words in the string
 */
int count_words(char *str)
{
int i, count = 0;

for (i = 0; str[i] != '\0'; ++i)
{
if ((i == 0 || str[i - 1] == ' ') && str[i] != ' ')
{
++count;
}
}

return (count);
}

/**
 * free_tab - Frees an array of strings
 * @tab: The array of strings to free
 *
 * Return: nothing
 */
void free_tab(char **tab)
{
int i;

for (i = 0; tab[i] != NULL; ++i)
{
free(tab[i]);
}

free(tab);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (words), or NULL on failure
 */
char **strtow(char *str)
{
char **words;
int i, j, k, len, word_count = 0;

if (str == NULL || *str == '\0')
{
return (NULL);
}

word_count = count_words(str);
words = malloc((word_count + 1) * sizeof(char *));
if (words == NULL)
{
return (NULL);
}

for (i = 0, j = 0; i < word_count; ++i)
{
while (str[j] == ' ')
{
++j;
}

len = 0;
while (str[j + len] != ' ' && str[j + len] != '\0')
{
++len;
}

words[i] = malloc((len + 1) * sizeof(char));
if (words[i] == NULL)
{
free_tab(words);
return (NULL);
}

for (k = 0; k < len; ++k)
{
words[i][k] = str[j + k];
}

words[i][k] = '\0';
j += len;
}

words[i] = NULL;

return (words);
}
