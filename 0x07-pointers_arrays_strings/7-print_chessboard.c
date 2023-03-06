#include "main.h"
/**
 * print_chessboard - Entry point
 * @a: array
 * Return: Always 0 (Success)
 */
void print_chessboard(char (*a)[8])
{
	int d;
	int b;

	for (d = 0; d < 8; d++)
	{
		for (b = 0; b < 8; b++)
			_putchar(a[d][b]);
		_putchar('\n');
	}
}

