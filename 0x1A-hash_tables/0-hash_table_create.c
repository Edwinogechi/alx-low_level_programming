#include "hash_tables.h"

/**
 * hash_table_create - Function that creates a hash table.
 * @size: The size of the given array.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - pointer to the new allocated hash table.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *New_table; /* Pointer to new hash table*/
	unsigned long int e;


	/* Allocate memmory for the hash table structure*/
	New_table = malloc(sizeof(hash_table_t));

	/* Check for memory allocation failure*/
	if (New_table == NULL)
	{
		return (NULL);
	}

	/*Set the hash table size to the given value*/
	New_table->size = size;

	/* Allocate memory for the array of pointers */
	New_table->array = malloc(sizeof(void *) * size);
	if (New_table->array == NULL) /* Check if malloc failed*/
	{
		free(New_table);
		return (NULL);
	}

	/* Initialize all the elements of the array to NUll*/

	for (e = 0; e < size; e++)
	{
		New_table->array[e] = NULL;
	}

	/* Return pointer to the newly created hash table*/
	return (New_table);
}
