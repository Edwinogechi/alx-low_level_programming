#include "main.h"

/**
 * print_alphabet_x10 - the function printing the alphabet ten times
 *
 * Return: always 0
 */

void print_alphabet_x10(void)
{
	int k;
	char l;

	for (k = 1 ; k <= 10 ; k++)
	{
		for (l = 'a' ; l <= 'z' ; l++)
			_putchar(l);
		_putchar('\n');
	}
}
