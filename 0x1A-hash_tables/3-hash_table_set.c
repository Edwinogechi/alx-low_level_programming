#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element to the hash table.
 * @ht: A pointer to the hash table to be added to.
 * @key: The key of the new element to add - can't be an empty string.
 * @value: The value associated with the key for the new element.
 *
 * Return: 1 if successful, 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	char *value_dup;
	unsigned long int index, i;

	/* Check if hash table or key or value is NULL or key is empty */
	if (!ht || !key || (strlen(key) == 0) || !value)
		return (0);

	/* Duplicate the value */
	value_dup = strdup(value);
	if (value_dup == NULL)
		return (0);

	/* Calculate the index for the key in the hash table */
	index = key_index((const unsigned char *)key, ht->size);

	/* Search for an existing node with the same key */
	for (i = index; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			/* Update the value of the existing node */
			free(ht->array[i]->value);
			ht->array[i]->value = value_dup;
			return (1);
		}
	}

	/* Create a new node for the key-value pair */
	new_node = malloc(sizeof(hash_node_t));

	if (new_node == NULL)
	{
		free(value_dup);
		return (0);
	}

	/* Duplicate the key */
	new_node->key = strdup(key); /* store key in new node */

	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->value = value_dup;
	new_node->next = ht->array[index]; /* attach new to head of list at index */
	ht->array[index] = new_node; /*index pointer assigned to new node */


	return (1);
}
