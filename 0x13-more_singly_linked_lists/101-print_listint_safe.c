#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	listint_t *loop_node = NULL;

	if (head == NULL)
		exit(98);

	loop_node = find_listint_loop((listint_t *)head);
	while (head != NULL)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;
		if (head == loop_node)
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			break;
		}
		head = head->next;
	}

	return (count);
}

/**
 * find_listint_loop - finds the node where a linked list loops
 * @head: pointer to the head of the list
 *
 * Return: the node where the loop starts, or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);
		}
	}

	return (NULL);
}
