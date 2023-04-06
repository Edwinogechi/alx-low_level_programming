#include "main.h"

/**
 * clear_bit - A function that sets the bit value of a given index to 0
 * @n: First parameter pointer to the unsigned long integer to modify
 * @index: Second parameter index of the bit to clear, starting from 0
 *
 * Return: 1 for success, or -1 if an error occured
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	/* Check if the index is within range */

	if (index > 63)

		return (-1);

	/* Clear the bit value at the given index to 0 */

	*n &= ~(1UL << index);

	return (1);

}

