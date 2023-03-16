#include "main.h"
#include <stdlib.h>

/**
* *argstostr - function that concatenates all arguments of a program
* @ac: number of arguments passed to the program
* @av: array of pointers to the arguments
*
* Return: Pointer to the new string (Success), NULL (Error)
*/
char *argstostr(int ac, char **av)
{
	int a, b, k, len = ac;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (a = 0; a < ac; a++)
	{
		for (b = 0; av[a][b] != '\0'; b++)
			len++;
		len++;
	}

	str = malloc(sizeof(char) * (len + 1));

	if (str == NULL)
		return (NULL);

	k = 0;

	for (a = 0; a < ac; a++)
	{
		for (b = 0; av[a][b] != '\0'; b++)
		{
			str[k] = av[a][b];
			k++;
		}
		str[k++] = '\n';
	}

	str[len] = '\0';

	return (str);
}
