#include <stdlib.h>
#include "main.h"

/**
 * *malloc_checked - allocating memory using the malloc function
 * @b: bytes to be allocated
 * Return: a pointer to the memory allocated
 */

void *malloc_checked(unsigned int b)
{

	void *ptr;

	ptr = malloc(b);

	if (ptr == NULL)

		exit(98);

	return (ptr);

}

