#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - Prints the keys and values of a hash table.
 * @ht: The hash table to print.
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0, j = 0;
	hash_node_t *Node = NULL;

	if (ht == NULL)
		return;

	printf("{");
	while (i < ht->size)
	{
		Node = ht->array[i];
		while (Node)
		{
			if (j > 0)
				printf(", ");
			printf("'%s': '%s'", Node->key, Node->value);
			Node = Node->next;
			j = 1;
		}
		i++;
	}
	printf("}\n");
}
