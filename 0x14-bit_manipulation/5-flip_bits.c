#include "main.h"

/**
 * flip_bits - A function that returns the number of bits to flip
 * to get from one number to another
 * @n: first parameter of unsigned long integer
 * @m: second parameter of unsigned long integer
 *
 * Return: number of bits to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	/* XOR of n and m and number of bits to flip */

	int i, flip_count = 0;

	unsigned long int temp;

	unsigned long int xor_result = n ^ m;


	/* Get the number of set bits in the  eXclusiveOR result */

	for (i = 63; i >= 0; i--)
	{
		temp = xor_result >> i;

		if (temp & 1)

			flip_count++;
	}

	return (flip_count);

}
