#include "search_algos.h"

int recurse_helper(int *array, size_t left, size_t right, int value);

/**
 * binary_search - function to search for value in array of sorted ints
 * @array: array to search for
 * @size: size of array to searched
 * @value: value to search in the array
 *
 * Return: index of value found; or -1 if not available
 */
int binary_search(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (recurse_helper(array, 0, size - 1, value));
}

/**
 * recurse_helper - function for recursive implement of binary search
 * @array: array to search for values
 * @left: leftmost index in the array
 * @right: rightmost index in the array
 * @value: value to search in the array
 *
 * Return: index of found value; or -1 if not available
 */
int recurse_helper(int *array, size_t left, size_t right, int value)
{
	size_t i = left, mid;

	if (left > right)
		return (-1);

	/* print search progress in the arrray */
	printf("Searching in array: %d", array[i++]);
	while (i <= right)
		printf(", %d", array[i++]);
	printf("\n");

	/* calculate mid of the given array*/
	mid = left + ((right - left) / 2);

	/* check if mid is the available value */
	if (array[mid] == value)
		return (mid);
	else if (array[mid] > value)
	{
		if (mid != 0)
			return (recurse_helper(array, left, mid - 1, value));
		else
			return (-1);
	}
	else
		return (recurse_helper(array, mid + 1, right, value));
}
