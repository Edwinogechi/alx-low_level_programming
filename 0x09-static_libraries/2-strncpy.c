#include "main.h"
#include <string.h>
/**
 * _strncpy - used to copy
 * @dest: parameter one
 * @src: parameter two
 * @n: parameter two
 * Return: the string
 */
char *_strncpy(char *dest, char *src, int n)
{
	strncpy(dest, src, n);
	return (dest);
}
