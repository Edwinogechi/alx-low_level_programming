#include "main.h"
#include <stdlib.h>

/**
 * _strdup - function that copies the string given as parameter
 * @str: The string to be copied.
 * Return: pointer to the copied string on (Success), NULL (Error)
 */
char *_strdup(char *str)
{
	char *duplicate;
	int i, len;


	i = 0;

	len = 0;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		len++;

	duplicate = malloc(sizeof(char) * (len + 1));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		duplicate[i] = str[i];

	duplicate[len] = '\0';

	return (duplicate);
}
