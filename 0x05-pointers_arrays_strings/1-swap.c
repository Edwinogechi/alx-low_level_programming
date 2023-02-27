#include "main.h"

/**
 * swap_int - swapping values of two intergers
 * @a: first interger to swap
 * @b: second interger to swap
 * Return: void
 */

void swap_int(int *a, int *b)
{
	int m;

	m = *a;

	*a = *b;

	*b = m;
}
