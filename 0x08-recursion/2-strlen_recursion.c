#include "main.h"

/**
 * _strlen_recursion - function to return length of string
 * @s: string parameter
 * Return: length of a string
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	s++;
	return (1 + _strlen_recursion(s));
}
