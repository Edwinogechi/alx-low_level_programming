#include "hash_tables.h"
/**
 * hash_table_get - Retrieve the value associated witha key in a hash table
 * @ht: A pointer to the hash table
 * @key: The key to retrieve the value of
 *
 * Return: The key value; NULL if key is not present
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	hash_node_t *node = NULL;

	if (!ht || !key)
		return (NULL);

	/* Calculate the index for the key in the hash table */
	index = hash_djb2((unsigned char *)key) % ht->size;

	if (ht->array[index]) /* if pointer at index is not NULL */
	{
		node = ht->array[index];
		while (node)
		{
			/* Traverse the linked list to find the matching key */
			if (strcmp(node->key, key) == 0)
				break;
			node = node->next;
		}
	}
	/* key doesn't exist in the given table */
	else
		return (NULL);

	/* Return the value associated with the key */
	return (node->value);
}
