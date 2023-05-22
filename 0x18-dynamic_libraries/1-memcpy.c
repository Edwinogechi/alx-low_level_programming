#include "main.h"
/**
 *_memcpy - function copying the memory area
 *@dest: memory where it is stored
 *@src: memory where it is copied
 *@n: number of bytes
 *
 *Return: copied memory with changed n byte
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int j = 0;
	int i = n;

	for (; j < i; j++)
	{
		dest[j] = src[j];
		n--;
	}
	return (dest);
}

