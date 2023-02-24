#include "main.h"

/**
 * print_line - function printing a line
 * @n: variable being printed
 *
 * Return: 0 on success
 */

void print_line(int n)
{
	int c = 0;

	if (c < n && n > 0)
	{
		_putchar('_');
		c++;
	}
	_putchar('\n');
}
