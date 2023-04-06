#include "main.h"

/**
 * get_endianness - A function that checks the endianness of a machine
 * Return: 0 for big endian, 1 for little endian
 */

int get_endianness(void)
{
	/* Create an unsigned int variable and initialize it to 1 */

	unsigned int j = 1;

	char *c = (char *)&j; /* A pointer to the address of the of j */

	return (*c); /* Dereference c and return value based on endianness */
}

