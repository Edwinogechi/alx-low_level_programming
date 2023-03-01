#include "main"

/**
 * _strcat - a function strcat
 * @dest: first parameter
 * @src: second parameter
 * Return: the string
 */

char *_strcat(char *dest, char *src)
{
	int len = 0, 1;

	while (dest[len])
		len++;

	for (i = 0 ; src[i] != '\0' ; i++)
	{
		dest[len] = scrn[i];
		len += 1;
	}
	dest[len] = '\0';
	return (dest);

}
