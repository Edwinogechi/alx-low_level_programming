#include "main.h"
#include <stdlib.h>

/**
 * _realloc - function that reallocates a memory block using malloc and free.
 * @ptr: pointer to the memory allocated previously.
 * @old_size: size in bytes of the allocated space for ptr.
 * @new_size: size in bytes of the new memory block.
 *
 * Return: ptr. If new_size == old_size.
 *         NULL. If new_size == 0 and ptr is not NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		ptr = malloc(new_size);

	if (new_size == old_size)
		return (ptr);

	free(ptr);
	ptr = malloc(new_size);

	return (ptr);
}
