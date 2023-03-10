#include "main.h"

/**
 *  _islower - a function printing lower case
 *  @c: parameter to be printed
 *
 *  Return: 1 if c is lowercase otherwise return zero
 */

int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
