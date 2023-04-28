#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: A pointer to a pointer to the head node of the list.
 * @str: The string to be added to the new node.
 *
 * Return: If memory allocation fails or head is NULL, NULL.
 *         Otherwise, the address of the new node.
 */
list_t *add_node_end(list_t **head, const char *str)
{
list_t *new_node, *temp_node;

if (head == NULL || str == NULL)
return (NULL);

new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);

new_node->str = strdup(str);
if (new_node->str == NULL)
{
free(new_node);
return (NULL);
}

new_node->next = NULL;

if (*head == NULL)
{
*head = new_node;
return (new_node);
}

temp_node = *head;
while (temp_node->next != NULL)
temp_node = temp_node->next;

temp_node->next = new_node;

return (new_node);
}

/**
 * _strlen - calculates the length of a string
 * @s: pointer to the string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
int len = 0;

while (*s++)
len++;

return (len);
}
