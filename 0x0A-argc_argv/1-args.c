#include <stdio.h>

/**
 * main - a function to print arg number
 * @argc: argc param
 * argv: array of number
 * Return: 0 on success
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
