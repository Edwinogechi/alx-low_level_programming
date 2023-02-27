#include "main.h"
#include <stdio.h>
/**
 * print_array - prints n element of an array of integers
 * @a: name of array
 * @n: int to be printed
 * Return: 0 on success
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < (n - 1); i++)
	{
		printf("%d, ", a[i]);
	}
		if (i == (n - 1))
		{
			printf("%d", a[n - 1]);
		}
			printf("\n");
}
