#include "main.h"

/**
 * print_binary - A function printing a binary equivalent to a decimal number
 * @n: The number to be printed in binary
 */
void print_binary(unsigned long int n)
{
	int j, numb = 0;

	unsigned long int current;

	/* Iterrate over the 64 bits in this case */

	for (j = 63; j >= 0; j--)
	{
		/*Right shift to extract the current bit from n by j bits */
		current = n >> j;

		/* If the bit is 1, print a 1 */
		if (current & 1)
		{
			_putchar('1');
			numb++;
		}
		/* If the outcome is even and numb is not zero print a 0 */

		else if (numb)
			_putchar('0');

	}
	/* If numb is still zero after loop ends, print a 0 */

	if (numb == 0)
		_putchar('0');
}
