#include "hash_tables.h"
/**
 * key_index - Find the index of key storage in the array of the hash table
 * @key: The key of the index to locate
 * @size: The size of the hash array
 *
 * Return: The index of key; -1 if key is unavailable
 * Desscription: Apply the djb2 algorithm
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
