#include "main.h"
#include <stdlib.h>

/**
 * create_array - function creating an array of chars and
 *                initializes it with a specific char.
 * @size: size of the array being initialized.
 * @c: The char to intialize the array with.
 *
 * Return: If size == 0 return NULL.
 *         Otherwise - a pointer to the array.
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
		return (NULL);

	array = malloc(sizeof(char) * size);

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
