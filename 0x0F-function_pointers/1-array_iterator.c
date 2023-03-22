#include "function_pointers.h"
#include <stdio.h>
/**
 * array_iterator - a function that prints each array element on a newl
 * @array: array
 * @size: number of elements to print
 * @action: the pointer to print in regular or hexadecimal
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;


	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}

