#include "lists.h"


/**
 * print_listint - prints all the elements of a linked list
 * @h: pointer to head of the listint_t list to be printed
 *
 * Return: the number of nodes in the list
 */

size_t print_listint(const listint_t *h)
{
	size_t numb = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);

		h = h->next;

		numb++;
	}

	return (numb);
}

