#include "main.h"

/**
 * set_bit - sets the bit value at a given index to 1
 * @n: the first parameter pointer to the unsigned long interger to modify
 * @index: index of the bit to set to 1, beginning from 0
 *
 * Return: 1 for success, -1 if an error occured
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	/* Check if the index is valid */

	if (index > 63)

		return (-1);

	/* set the bit value at the given index to one */

	*n |= (1UL << index);

	return (1);

}
