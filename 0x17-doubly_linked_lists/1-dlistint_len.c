#include "lists.h"

/**
 * dlistint_len - prints all the elements of a linked dlistint_t list
 * @h: linked list head of type dlistint_len to print
 *
 * Return: number of elements in a list
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;

		h = h->next;
	}

	return (num);
}
