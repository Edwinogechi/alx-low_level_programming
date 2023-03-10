#include <stdio.h>

/**
 * main - major function
 * @argc: argc parameter
 * @argv: array of the command used
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
