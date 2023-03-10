#include <stdio.h>

/**
 * main - main function to print name
 * @argc: argc parameter
 * @argv: an array of the command used
 * Return: 0 on  success
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);
	return (0);
}
