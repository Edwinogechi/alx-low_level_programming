#include <stdio.h>
/**
 * main - major function
 * Description: prints even-valued numbers below 4,000,000
 *
 * Return: 0
 */
int main(void)
{
	int j = 0, k = 1, next = 0;
	int sum = 0;

	while (next < 4000000)
	{
		next = j + k;
		j = k;
		k = next;
		if (next % 2 == 0)
			sum += next;
	}
	printf("%i\n", sum);
	return (0);
}
