#include "main.h"

/**
 * _strlen - to return the length of a string
 * @s: character checking the length of the string
 * Return: 0
 */

int _strlen(char *s)
{
	int i = 0; /* begin counting from 0*/

	for (; *s++;)
		i++;
	return (i);
}

