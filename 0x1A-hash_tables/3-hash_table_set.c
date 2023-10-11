#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table where the element will be added.
 * @key: The key to be added.
 * @value: The value associated with the key (must be duplicated).
 *
 * Return: 1 if it succeeds, 0 otherwise.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *New_n = NULL;
	unsigned long int index;

	if (key == NULL || strcmp(key, "") == 0 || ht == NULL)
		return (0);

	index = key_index((unsigned char *)key, ht->size);
	if (ht->array[index] != NULL)
		if (strcmp(ht->array[index]->key, key) == 0)
		{
			free(ht->array[index]->value);
			ht->array[index]->value = strdup(value);
			return (1);
		}

	New_n = malloc(sizeof(hash_node_t));
	if (New_n == NULL)
		return (0);

	New_n->key = strdup(key);
	New_n->value = strdup(value);
	New_n->next = ht->array[index];
	ht->array[index] = New_n;
	return (1);

}
