#include "main.h"

int check_prime(int, int);

/**
 * is_prime_number - function printing prime numbers
 * @n: parameter
 * Return: interger
 */
int is_prime_number(int n)
{
	return (check_prime(n, 1));
}

/**
 * check_prime - function checking prime numbers
 * @n: interger
 * @i: iterator
 * Return: a 0 or 1
 */
int check_prime(int n, int i)
{
	if (n <= 1)
		return (0);
	if (n % i == 0 && i > 1)
		return (0);
	if ((n / i) < i)
		return (1);
	return (check_prime(n, i + 1));
}
