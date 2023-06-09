#include "hash_tables.h"
/**
 * hash_table_print - print hash table
 * @ht: hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *head = NULL;
	unsigned long int i = 0;
	unsigned long int j;

	if (ht == NULL) /* Check if hash table exists */
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (j == 1)
				printf(", ");

			head = ht->array[i];
			while (head != NULL)
			{
				printf("'%s': '%s'", head->key, head->value);
				head = head->next;
				if (head != NULL)
					printf(", "); /* print delimiter */
			}
			j = 1;
		}
	}

	printf("}\n");

}
