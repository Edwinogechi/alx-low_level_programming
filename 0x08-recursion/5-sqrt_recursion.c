#include "main.h"

int _sqrt(int, int);

/**
 * _sqrt_recursion - function returning natural squareroot
 * @n: parameter being squarerooted
 * Return: square root of a number
 */

int _sqrt_recursion(int n)
{
	return (_sqrt(n, 1));
}

/**
 * _sqrt - recursive squareroot
 * @n: number param
 * @i: iterator
 * Return: a number
 */
int _sqrt(int n, int i)
{
	int square = i * i;

	if (square > n)
		return (-1);
	if (square == n)
		return (i);
	return (_sqrt(n, i + 1));
}
