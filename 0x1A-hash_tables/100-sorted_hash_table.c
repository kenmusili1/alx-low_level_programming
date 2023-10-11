#include <stdlib.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of new sorted hash table.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new sorted hash table.
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *New_table;
	unsigned long int i;

	New_table = malloc(sizeof(shash_table_t));
	if (New_table == NULL)
		return (NULL);

	New_table->size = size;
	New_table->array = malloc(sizeof(shash_node_t *) * size);
	if (New_table->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		New_table->array[i] = NULL;
	New_table->shead = NULL;
	New_table->stail = NULL;

	return (New_table);
}

/**
 * shash_table_set - Adds an element to the sorted hash table.
 * @ht: The sorted hash table where the element will be added.
 * @key: The key to be added.
 * @value: The value associated with the key (must be duplicated).
 *
 * Return: 1 if it succeeds, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *current;
	char *value_copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->shead;
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = value_copy;
			return (1);
		}
		current = current->snext;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
	{
		free(value_copy);
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(value_copy);
		free(new_node);
		return (0);
	}
	new_node->value = value_copy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (ht->shead == NULL)
	{
		new_node->sprev = NULL;
		new_node->snext = NULL;
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		current = ht->shead;
		while (current->snext != NULL && strcmp(current->snext->key, key) < 0)
			current = current->snext;
		new_node->sprev = current;
		new_node->snext = current->snext;
		if (current->snext == NULL)
			ht->stail = new_node;
		else
			current->snext->sprev = new_node;
		current->snext = new_node;
	}

	return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key from the sorted hash table.
 * @ht: The sorted hash table to look into.
 * @key: The key to search for.
 *
 * Return: The value associated with the key, or NULL if the key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *current;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	current = ht->shead;
	while (current != NULL && strcmp(current->key, key) != 0)
		current = current->snext;

	return ((current == NULL) ? NULL : current->value);
}

/**
 * shash_table_print - Prints the sorted hash table using the sorted linked list.
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;

	if (ht == NULL)
		return;

	current = ht->shead;
	printf("{");
	while (current != NULL)
	{
		printf("'%s': '%s'", current->key, current->value);
		current = current->snext;
		if (current != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *new_node;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		new_node = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = new_node;
	}

	free(head->array);
	free(head);
}

/**
 * shash_table_print_rev - Prints in reverse order.
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;

	if (ht == NULL)
		return;

	current = ht->stail;
	printf("{");
	while (current != NULL)
	{
		printf("'%s': '%s'", current->key, current->value);
		current = current->sprev;
		if (current != NULL)
			printf(", ");
	}
	printf("}\n");
}
