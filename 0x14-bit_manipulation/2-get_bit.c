#include "main.h"

/**
 * get_bit - function printing the bit value at an index in a decimal number
 * @n: the parameter to search for
 * @index: index of the bit
 *
 * Return: the value of the bit at index index or -1
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	/* Check if index is greater than or equal to n */

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	/* Right shift the bit at the given index then mask it with 1 */

	bit_val = (n >> index) & 1;

	return (bit_val);

}

