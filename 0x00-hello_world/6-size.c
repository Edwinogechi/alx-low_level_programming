#include <stdio.h>

/**
 * main - its major function
 *
 * Return: 0 on success
 */

int main(void)
{
	char a;
	int b;
	long int c;
	float f;

	printf("Size of a char: %lu byte(s)", sizeof(char));
	printf("Size of an int: %lu byte(s)", sizeof(int));
	printf("Size of a long int: %lu byte(s)", sizeof(long int));
	printf("Size of a long long int: %lu byte(s)", sizeof(long long int));
	printf("Size of a float: %lu byte(s)", sizeof(float));
	return (0);

}
