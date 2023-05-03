#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list, handles loops
 * @head: Pointer to the beginning of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	listint_t *loop_node = NULL;
	const listint_t *temp = head;

	loop_node = find_loop(head);
	while (temp != NULL)
	{
		printf("[%p] %d\n", (void *)temp, temp->n);
		count++;
		if (temp == loop_node)
			break;
		temp = temp->next;
	}

	if (loop_node)
	{
		printf("-> [%p] %d\n", (void *)loop_node, loop_node->n);
		count++;
	}

	return (count);
}

/**
 * find_loop - Finds the first node of a loop in a linked list
 * @head: Pointer to the beginning of the list
 *
 * Return: The first node of the loop, or NULL if there is no loop
 */
listint_t *find_loop(const listint_t *head)
{
	const listint_t *slow, *fast;

	if (head == NULL || head->next == NULL)
		return (NULL);

	slow = head->next;
	fast = head->next->next;

	while (fast != NULL && fast->next != NULL)
	{
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return ((listint_t *)slow);
		}
		slow = slow->next;
		fast = fast->next->next;
	}

	return (NULL);
}
