#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a linked list safely
 *
 * @h: Double pointer to the head of the linked list
 *
 * Return: The number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *next_node;

	if (h == NULL || *h == NULL)
		return (count);

	current = *h;
	*h = NULL;

	while (current != NULL)
	{
		count++;
		next_node = current->next;
		free(current);
		if (current <= next_node)
			break;
		current = next_node;
	}

	return (count);
}
