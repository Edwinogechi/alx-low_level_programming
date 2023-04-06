#include "main.h"

/**
 * binary_to_uint - A function converting a binary number to unsigned int
 * @b: The string containing the binary number to be converted
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int outcome = 0;

	/* Check fo a null pointer first */
	if (!b)
	{
		return (0);
	}

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
		{
			return (0);
		}

	outcome = (outcome << 1) | (b[i] - '0');

	}

	return (outcome);
}

